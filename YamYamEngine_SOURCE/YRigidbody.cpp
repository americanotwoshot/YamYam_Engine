#include "YRigidbody.h"
#include "YTime.h"
#include "YTransform.h"
#include "YGameObject.h"

namespace yam
{
	Rigidbody::Rigidbody()
		:Component(enums::eComponentType::Rigidbody)
		, mMass(1.0f)
		, mFriction(10.0f)
		, mForce(Vector2::Zero)
		, mAccelation(Vector2::Zero)
		, mVelocity(Vector2::Zero)
		, mGravity(Vector2::Zero)
	{
	}
	Rigidbody::~Rigidbody()
	{
	}

	void Rigidbody::Initialize()
	{
	}
	void Rigidbody::Update()
	{
		// f = m * a;
		// a = f / m;
		mAccelation = mForce / mMass;

		mVelocity += mAccelation * Time::DeltaTime();

		if (!(mVelocity == Vector2::Zero))
		{
			// �ӵ� �ݴ� �������� ������ �ۿ�
			Vector2 friction = -mVelocity;
			friction = friction.normarlize() * mFriction * mMass * Time::DeltaTime();

			// ���������� ���� �ӵ� ���ҷ��� ���� �ӵ����� ū ���
			if (mVelocity.length() <= friction.length())
			{
				mVelocity = Vector2::Zero;
			}
			else
			{
				mVelocity += friction;
			}
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos = pos + mVelocity * Time::DeltaTime();
		tr->SetPosition(pos);

		mForce.clear();
	}
	void Rigidbody::LateUpdate()
	{
	}
	void Rigidbody::Render(HDC hdc)
	{
	}
}