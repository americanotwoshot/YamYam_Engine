#pragma once
#include "YEntity.h"
#include "YComponent.h"

namespace yam
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void ImageLoad(const std::wstring& path);

	private:
		// ���ȭ��
		Gdiplus::Image* mImage;
		
		// ���� ������Ʈ�� ũ��
		float mWidth;
		float mHeight;
	};
}

