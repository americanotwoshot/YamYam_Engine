#include "YBulletObject.h"
#include "YTime.h"

namespace yam
{
	BulletObject::BulletObject()
		: mSpeed(500.0f)
		, mX(0.0f)
		, mY(0.0f)
	{
	}

	BulletObject::~BulletObject()
	{
	}

	void BulletObject::Update()
	{
		mY -= mSpeed * Time::DeltaTime();
	}

	void BulletObject::LateUpdate()
	{

	}

	void BulletObject::Render(HDC hdc)
	{
		HBRUSH newBrush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

		Ellipse(hdc, 25 + mX, -25 + mY, 75 + mX, 25 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(newBrush);
	}
}

