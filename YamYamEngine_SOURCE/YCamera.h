#pragma once
#include "YComponent.h"

namespace yam
{
	using namespace yam::math;
	class Camera : public Component
	{
	public:
		Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; }
		Vector2 CalculateTilePosition(Vector2 pos) { return pos + mDistance; }

		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTarget(GameObject* target) { mTarget = target; }

	private:
		class GameObject* mTarget;	// ī�޶� ����ٴϴ� ���
		Vector2 mDistance;			// ī�޶������ �Ÿ�
		Vector2 mResolution;		// ȭ�� �ػ�
		Vector2 mLookPosition;		// ī�޶� ���� ����
	};
}

