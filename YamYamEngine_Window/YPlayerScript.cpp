#include "YPlayerScript.h"
#include "YInput.h"
#include "YTransform.h"
#include "YTime.h"
#include "YGameObject.h"

namespace yam
{
	PlayerScript::PlayerScript()
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
		if (Input::GetKey(eKeyCode::Right))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			math::Vector2 pos = tr->GetPosition();
			pos.x += Time::DeltaTime() * 100.0f;
			tr->SetPosition(pos);
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			math::Vector2 pos = tr->GetPosition();
			pos.x -= Time::DeltaTime() * 100.0f;
			tr->SetPosition(pos);
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			math::Vector2 pos = tr->GetPosition();
			pos.y -= Time::DeltaTime() * 100.0f;
			tr->SetPosition(pos);
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			math::Vector2 pos = tr->GetPosition();
			pos.y += Time::DeltaTime() * 100.0f;
			tr->SetPosition(pos);
		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
}