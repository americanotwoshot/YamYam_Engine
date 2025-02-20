#include "YGameObject.h"

namespace yam
{
	GameObject::GameObject()
	{

	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
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