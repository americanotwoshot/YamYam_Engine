#pragma once
#include "..\\YamYamEngine_SOURCE\\YScript.h"
#include "..\\YamYamEngine_SOURCE\\YTexture.h"

namespace yam
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Sleep,
			GiveWater,
			Attack,
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void AttackEffect();

		void OnCollisionEnter(class Collider* other) override;
		void OnCollisionStay(class Collider* other) override;
		void OnCollisionExit(class Collider* other) override;

	private:
		void idle();
		void move();
		void giveWater();

	private:
		eState mState;
		class Animator* mAnimator;
	};
}

