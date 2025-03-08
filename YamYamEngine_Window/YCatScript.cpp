#include "YCatScript.h"
#include "YInput.h"
#include "YTime.h"
#include "YGameObject.h"
#include "YAnimator.h"
#include "YObject.h"

namespace yam
{
	CatScript::CatScript()
		: mState(CatScript::eState::Idle)
		, mAnimator(nullptr)
		, mTime(0.0f)
		, mDeathTime(0.0f)
		, mDest(Vector2::Zero)
		, mRadian(0.0f)
	{
	}
	CatScript::~CatScript()
	{
	}

	void CatScript::Initialize()
	{

	}
	void CatScript::Update()
	{
		//mDeathTime += Time::DeltaTime();
		//if (mDeathTime > 5.0f)
		//{
		//	object::Destroy(GetOwner());
		//}

		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<Animator>();

		switch (mState)
		{
		case yam::CatScript::eState::Idle:
			idle();
			break;
		case yam::CatScript::eState::Walk:
			move();
			break;
		case yam::CatScript::eState::Sleep:
			break;
		case yam::CatScript::eState::LayDown:
			layDown();
			break;
		case yam::CatScript::eState::Attack:
			break;
		default:
			break;
		}
	}
	void CatScript::LateUpdate()
	{
	}
	void CatScript::Render(HDC hdc)
	{
	}

	void CatScript::idle()
	{
		mTime += Time::DeltaTime();

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		// 마우스 위치 이동( 벡터의 뺄셈 활용 )
		//Transform* plTr = mPlayer->GetComponent<Transform>();
		//Vector2 dest = mDest - plTr->GetPosition();
		//pos += dest.normarlize() * (100.0f * Time::DeltaTime());

		// 삼각함수를 통한 이동
		//mRadian += 5.0f * Time::DeltaTime();
		//pos += Vector2(1.0f, cosf(mRadian)) * (100.0f * Time::DeltaTime());

		// 마우스 위치 방향으로 회전 후 이동( 벡터의 뺄셈 활용 )
		Transform* plTr = mPlayer->GetComponent<Transform>();
		Vector2 dest = mDest - plTr->GetPosition();
		dest.normarlize();

		float rotDegree = Vector2::Dot(dest, Vector2::Right);
		rotDegree = acosf(rotDegree);
		rotDegree = ConvertRadian(rotDegree);

		pos += dest * (100.0f * Time::DeltaTime());

		tr->SetPosition(pos);

		//if (mTime > 3.0f)
		//{
		//	srand(time(NULL));
		//	mState = CatScript::eState::Walk;
		//	int direction = rand() % 4;
		//	mDirection = (eDirection)direction;
		//	playWalkAnimationByDirection(mDirection);
		//	mTime = 0.0f;
		//}
	}
	void CatScript::move()
	{
		mTime += Time::DeltaTime();
		if (mTime > 2.0f)
		{
			int isLayDown = rand() % 2;
			if (isLayDown)
			{
				mState = CatScript::eState::LayDown;
				mAnimator->PlayAnimation(L"LayDown", false);
			}
			else
			{
				mState = CatScript::eState::Idle;
				mAnimator->PlayAnimation(L"SitDown", false);
			}
			mTime = 0.0f;
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		translate(tr);
	}

	void CatScript::layDown()
	{
	}

	void CatScript::playWalkAnimationByDirection(eDirection dir)
	{
		switch (dir)
		{
		case yam::CatScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftWalk", true);
			break;
		case yam::CatScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightWalk", true);
			break;
		case yam::CatScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownWalk", true);
			break;
		case yam::CatScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpWalk", true);
			break;
		default:
			assert(false);
			break;
		}
	}
	void CatScript::translate(Transform* tr)
	{
		Vector2 pos = tr->GetPosition();
		switch (mDirection)
		{
		case yam::CatScript::eDirection::Left:
			pos.x -= 100.0f * Time::DeltaTime();
			break;
		case yam::CatScript::eDirection::Right:
			pos.x += 100.0f * Time::DeltaTime();
			break;
		case yam::CatScript::eDirection::Down:
			pos.y += 100.0f * Time::DeltaTime();
			break;
		case yam::CatScript::eDirection::Up:
			pos.y -= 100.0f * Time::DeltaTime();
			break;
		default:
			assert(false);
			break;
		}
		tr->SetPosition(pos);
	}
}