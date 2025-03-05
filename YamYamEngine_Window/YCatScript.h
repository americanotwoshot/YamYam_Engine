#pragma once
#include "..\\YamYamEngine_SOURCE\\YScript.h"
#include "..\\YamYamEngine_SOURCE\\YTransform.h"

namespace yam
{
	class CatScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Sleep,
			LayDown,
			Attack,
		};

		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
			End,
		};

		CatScript();
		~CatScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void idle();
		void move();
		void layDown();
		void playWalkAnimationByDirection(eDirection dir);
		void translate(Transform* tr);

	private:
		eState mState;
		class Animator* mAnimator;
		eDirection mDirection;
		float mTime;
	};
}

