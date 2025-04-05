#pragma once
#include "YTexture.h"

namespace yam::graphics
{
	enum class eRenderTargetFormat
	{
		None = 0,
		RGBA8,
		RED_INTEGER,
		DEPTH24STENCIL8,
		SHADER_RESOURCE,
		Depth = DEPTH24STENCIL8,
	};

	// 렌더 타겟의 사용 목적을 지정하는 구조체
	struct RenderTargetTextureSpecification
	{
		RenderTargetTextureSpecification() = default;
		RenderTargetTextureSpecification(eRenderTargetFormat format)
			: TextureFormat(format) {}

		eRenderTargetFormat TextureFormat = eRenderTargetFormat::None;
	};

	// 렌더 타겟들(여러개)의 사용 목적을 지정하는 구조체
	struct RenderTargetAttachmentSpecification
	{
		RenderTargetAttachmentSpecification() = default;
		RenderTargetAttachmentSpecification(std::initializer_list<RenderTargetTextureSpecification> attachments)
			: Attachments(attachments) {}

		std::vector<RenderTargetTextureSpecification> Attachments;
	};

	struct RenderTargetSpecification
	{
		UINT Width = 0, Height = 0;
		RenderTargetAttachmentSpecification Attachments;
		UINT Samples = 1;

		bool SwapChainTarget = false;
	};

	class RenderTarget
	{
	public:
		RenderTarget(const RenderTargetSpecification& spec);
		virtual ~RenderTarget();

		static RenderTarget* Create(const RenderTargetSpecification& spec);

		void Invalidate();
		void Bind();
		void Unbind();

		void Resize(UINT width, UINT height);
		int ReadPixel(uint32_t attachmentIndex, int x, int y);

		void ClearAttachment(UINT index, const void* value);

		Texture* GetAttachmentTexture(UINT index) { return mAttachments[index]; }
		RenderTargetSpecification& GetSpecification() { return mSpecification; }

	private:
		RenderTargetSpecification mSpecification;

		std::vector<RenderTargetTextureSpecification> mSpecifications;
		RenderTargetTextureSpecification mDepthAttachmentSpecification;

		std::vector<Texture*> mAttachments;
		Texture* mDepthAttachment;
	};
}

