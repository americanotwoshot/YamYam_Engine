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
		class GameObject* mTarget;	// 카메라가 따라다니는 대상
		Vector2 mDistance;			// 카메라까지의 거리
		Vector2 mResolution;		// 화면 해상도
		Vector2 mLookPosition;		// 카메라가 보는 방향
	};
}

