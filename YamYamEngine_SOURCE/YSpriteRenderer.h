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
		// 배경화면
		Gdiplus::Image* mImage;
		
		// 게임 오브젝트의 크기
		float mWidth;
		float mHeight;
	};
}

