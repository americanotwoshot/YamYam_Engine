#include "YPlayerScript.h"
#include "YInput.h"
#include "YTransform.h"
#include "YTime.h"
#include "YGameObject.h"
#include "YAnimator.h"
#include "YResources.h"
#include "YObject.h"
#include "YCat.h"
#include "YCatScript.h"
#include "YCollider.h"

namespace yam
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, mAnimator(nullptr)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
		
	}
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<Animator>();

		switch (mState)
		{
		case yam::PlayerScript::eState::Idle:
			idle();
			break;
		case yam::PlayerScript::eState::Walk:
			move();
			break;
		case yam::PlayerScript::eState::Sleep:
			break;
		case yam::PlayerScript::eState::GiveWater:
			giveWater();
			break;
		case yam::PlayerScript::eState::Attack:
			break;
		default:
			break;
		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}

	void PlayerScript::AttackEffect()
	{
		// cat
		Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
		CatScript* catSrc = cat->AddComponent<CatScript>();

		catSrc->SetPlayer(GetOwner());

		graphics::Texture* catTexture = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
		catAnimator->CreateAnimation(L"DownWalk", catTexture
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"RightWalk", catTexture
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"UpWalk", catTexture
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"LeftWalk", catTexture
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"SitDown", catTexture
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.5f);
		catAnimator->CreateAnimation(L"Grooming", catTexture
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.5f);
		catAnimator->CreateAnimation(L"LayDown", catTexture
			, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.5f);

		catAnimator->PlayAnimation(L"SitDown", false);

		Transform* tr = GetOwner()->GetComponent<Transform>();

		cat->GetComponent<Transform>()->SetIndexPosition(tr->GetPosition());
		cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
	
		Vector2 mousePos = Input::GetMousePosition();
		catSrc->mDest = mousePos;
	}

	void PlayerScript::OnCollisionEnter(Collider* other)
	{
		int a = 0;
	}
	void PlayerScript::OnCollisionStay(Collider* other)
	{
		int a = 0;
	}
	void PlayerScript::OnCollisionExit(Collider* other)
	{
		int a = 0;
	}

	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::LButton))
		{
			mState = PlayerScript::eState::GiveWater;
			mAnimator->PlayAnimation(L"FrontGiveWater", false);

			Vector2 mousePos = Input::GetMousePosition();
		}
		//if (Input::GetKey(eKeyCode::D))
		//{
		//	mState = PlayerScript::eState::Walk;
		//	mAnimator->PlayAnimation(L"RightWalk");
		//}
		//if (Input::GetKey(eKeyCode::A))
		//{
		//	mState = PlayerScript::eState::Walk;
		//	mAnimator->PlayAnimation(L"LeftWalk");
		//}
		//if (Input::GetKey(eKeyCode::W))
		//{
		//	mState = PlayerScript::eState::Walk;
		//	mAnimator->PlayAnimation(L"UpWalk");
		//}
		//if (Input::GetKey(eKeyCode::S))
		//{
		//	mState = PlayerScript::eState::Walk;
		//	mAnimator->PlayAnimation(L"DownWalk");
		//}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::W))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetIndexPosition(pos);
	}
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::W))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetIndexPosition(pos);

		if (Input::GetKeyUp(eKeyCode::D) || Input::GetKeyUp(eKeyCode::A)
			|| Input::GetKeyUp(eKeyCode::W) || Input::GetKeyUp(eKeyCode::S))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"SitDown", false);
		}
	}
	void PlayerScript::giveWater()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}
}