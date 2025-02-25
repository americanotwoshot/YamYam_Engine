#pragma once
#include "YComponent.h"

namespace yam
{
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(float x, float y)
		{
			mX = x; mY = y;
		}

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }
	private:
		// ���� ������Ʈ�� ��ǥ
		float mX;
		float mY;
	};
}

