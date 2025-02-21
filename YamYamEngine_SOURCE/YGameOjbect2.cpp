#include "YGameOjbect2.h"

namespace yam
{
	GameOjbect2::GameOjbect2()
	{
	}

	GameOjbect2::~GameOjbect2()
	{
	}

	void GameOjbect2::Update()
	{
		if (GetAsyncKeyState('W') & 0x8000)
		{
			mY -= 0.01f;
		}
		if (GetAsyncKeyState('S') & 0x8000)
		{
			mY += 0.01f;
		}
		if (GetAsyncKeyState('A') & 0x8000)
		{
			mX -= 0.01f;
		}
		if (GetAsyncKeyState('D') & 0x8000)
		{
			mX += 0.01f;
		}
	}

	void GameOjbect2::LateUpdate()
	{

	}

	void GameOjbect2::Render(HDC hdc)
	{
		HBRUSH newBrush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

		Ellipse(hdc, 800 + mX, 500 + mY, 900 + mX, 600 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(newBrush);
	}
}

