#pragma once
#include "YResource.h"
#include "YGraphicDevice_DX11.h"

namespace yam::graphics
{
	class Shader : public Resource
	{
	public:
		Shader();
		virtual ~Shader();

		virtual HRESULT Save(const std::wstring& path) override;
		virtual HRESULT Load(const std::wstring& path) override;

		bool Create(const eShaderStage stage, const std::wstring& fileName);
		bool CreateVertexShader(const std::wstring& fileName);
		bool CreatePixelShader(const std::wstring& fileName);

		void Bind();

		[[nodiscard]] Microsoft::WRL::ComPtr<ID3DBlob> GetVSBlob() { return mVSBlob; }
		[[nodiscard]] Microsoft::WRL::ComPtr<ID3DBlob> GetHSBlob() { return mHSBlob; }
		[[nodiscard]] Microsoft::WRL::ComPtr<ID3DBlob> GetDSBlob() { return mDSBlob; }
		[[nodiscard]] Microsoft::WRL::ComPtr<ID3DBlob> GetGSBlob() { return mGSBlob; }
		[[nodiscard]] Microsoft::WRL::ComPtr<ID3DBlob> GetPSBlob() { return mPSBlob; }

		[[nodiscard]] Microsoft::WRL::ComPtr<ID3D11VertexShader>	GetVS() { return mVS; }
		[[nodiscard]] Microsoft::WRL::ComPtr<ID3D11HullShader>		GetHS() { return mHS; }
		[[nodiscard]] Microsoft::WRL::ComPtr<ID3D11DomainShader>	GetDS() { return mDS; }
		[[nodiscard]] Microsoft::WRL::ComPtr<ID3D11GeometryShader>	GetGS() { return mGS; }
		[[nodiscard]] Microsoft::WRL::ComPtr<ID3D11PixelShader>		GetPS() { return mPS; }

		void SetRasterizerState(const eRasterizerState state) { mRasterizerState = state; }
		void SetBlendState(const eBlendState state) { mBlendState = state; }
		void SetDepthStencilState(const eDepthStencilState state) { mDepthStencilState = state; }

	private:
		static bool bWireframe;

		Microsoft::WRL::ComPtr<ID3DBlob> mVSBlob;
		Microsoft::WRL::ComPtr<ID3DBlob> mHSBlob;
		Microsoft::WRL::ComPtr<ID3DBlob> mDSBlob;
		Microsoft::WRL::ComPtr<ID3DBlob> mGSBlob;
		Microsoft::WRL::ComPtr<ID3DBlob> mPSBlob;

		Microsoft::WRL::ComPtr<ID3D11VertexShader> mVS;
		Microsoft::WRL::ComPtr<ID3D11HullShader> mHS;
		Microsoft::WRL::ComPtr<ID3D11DomainShader> mDS;
		Microsoft::WRL::ComPtr<ID3D11GeometryShader> mGS;
		Microsoft::WRL::ComPtr<ID3D11PixelShader> mPS;

		graphics::eRasterizerState mRasterizerState;
		graphics::eBlendState mBlendState;
		graphics::eDepthStencilState mDepthStencilState;
	};
}
