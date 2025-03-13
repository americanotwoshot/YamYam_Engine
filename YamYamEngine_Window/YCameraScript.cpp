#include "YCameraScript.h"
#include "YGameObject.h"
#include "YTransform.h"
#include "YInput.h"
#include "YTime.h"

namespace yam
{
	CameraScript::CameraScript()
	{
	}
	CameraScript::~CameraScript()
	{
	}

	void CameraScript::Initialize()
	{
	}
	void CameraScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetIndexPosition(pos);
	}
	void CameraScript::LateUpdate()
	{
	}
	void CameraScript::Render(HDC hdc)
	{
	}
}