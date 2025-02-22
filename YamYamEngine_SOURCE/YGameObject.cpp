#include "YGameObject.h"
#include "YInput.h"
#include "YTime.h"
#include "YBulletObject.h"

namespace yam
{
	GameObject::GameObject()
		: mX(0.0f)
		, mY(0.0f)
	{

	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Update()
	{
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::Left))
		{
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::Right))
		{
			mX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::Up))
		{
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::Down))
		{
			mY += speed * Time::DeltaTime();
		}

		if (Input::GetKeyDown(eKeyCode::Space)) 
		{
			BulletObject* newBullet = new BulletObject();
			newBullet->SetPosition(mX, mY);
			bulletFactory.emplace_back(*newBullet);
		}

		for (auto it = bulletFactory.begin(); it != bulletFactory.end(); ++it) {
			it->Update();
		}
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{
		// 파랑 브러쉬 생성 및 할당(도형 내부 색)
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		// 빨강 선 생성 및 할당(도형 선)
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		// 사각형 생성
		Rectangle(hdc, 500 + mX, 500 + mY, 600 + mX, 600 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
		SelectObject(hdc, oldPen);
		DeleteObject(redPen);

		// 원 생성
		//Ellipse(hdc, 200, 100, 300, 200);

		// 스톡 오브젝트 : 기본으로 자주 사용되는 GDI 오브젝트들을 미리 만들어둠.
		//HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
		//oldBrush = (HBRUSH)SelectObject(hdc, grayBrush);
		//Rectangle(hdc, 400, 400, 500, 500);
		//SelectObject(hdc, oldBrush);

		for (auto it = bulletFactory.begin(); it != bulletFactory.end(); ++it) {
			it->Render(hdc);
		}

	}
}