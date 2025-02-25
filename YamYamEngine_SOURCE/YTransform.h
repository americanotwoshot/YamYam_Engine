#pragma once
#include "YComponent.h"
#include "CommonInclude.h"

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

		void SetPosition(yam::math::Vector2 pos)
		{
			mPosition.x = pos.x; mPosition.y = pos.y;
		}

		yam::math::Vector2 GetPosition() { return mPosition; }
	private:
		// ���� ������Ʈ�� ��ǥ
		yam::math::Vector2 mPosition;
	};
}

