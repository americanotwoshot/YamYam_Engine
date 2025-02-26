#include "YPlayer.h"
#include "YInput.h"
#include "YTransform.h"
#include "YTime.h"

namespace yam
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}
	void Player::Update()
	{
		GameObject::Update();
	}
	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

		if (Input::GetKey(eKeyCode::Right))
		{
			Transform* tr = GetComponent<Transform>();
			math::Vector2 pos = tr->GetPosition();
			pos.x += Time::DeltaTime() * 100.0f;
			tr->SetPosition(pos);
		}
	}
	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}