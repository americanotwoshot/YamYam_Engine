#include "YGameObject.h"
#include "YInput.h"

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
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += 0.01f;
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mY += 0.01f;
		}
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{
		// �Ķ� �귯�� ���� �� �Ҵ�(���� ���� ��)
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		// ���� �� ���� �� �Ҵ�(���� ��)
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		// �簢�� ����
		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
		SelectObject(hdc, oldPen);
		DeleteObject(redPen);

		// �� ����
		//Ellipse(hdc, 200, 100, 300, 200);

		// ���� ������Ʈ : �⺻���� ���� ���Ǵ� GDI ������Ʈ���� �̸� ������.
		//HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
		//oldBrush = (HBRUSH)SelectObject(hdc, grayBrush);
		//Rectangle(hdc, 400, 400, 500, 500);
		//SelectObject(hdc, oldBrush);
	}
}