#include "YCollider.h"
#include "YScript.h"
#include "YGameObject.h"

namespace yam
{
	UINT32 Collider::mCollisionID = 1;
	Collider::Collider(eColliderType type)
		:Component(enums::eComponentType::Collider)
		, mType(type)
		, mID(mCollisionID++)
		, mSize(Vector2::One)
		, mOffset(Vector2::Zero)
	{
	}
	Collider::~Collider()
	{
	}

	void Collider::Initialize()
	{
	}
	void Collider::Update()
	{
	}
	void Collider::LateUpdate()
	{
	}
	void Collider::Render()
	{
	}

	void Collider::OnCollisionEnter(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionEnter(other);
	}
	void Collider::OnCollisionStay(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionStay(other);
	}
	void Collider::OnCollisionExit(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionExit(other);
	}
}