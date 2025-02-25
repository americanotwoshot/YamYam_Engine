#pragma once
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

		void SetSize(float w, float h)
		{
			mWidth = w; mHeight = h;
		}

	private:
		// 게임 오브젝트의 크기
		float mWidth;
		float mHeight;

		GameObject* mOwner;
	};
}

