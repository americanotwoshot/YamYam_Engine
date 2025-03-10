#include "YBoxCollider2D.h"
#include "YTransform.h"
#include "YGameObject.h"

namespace yam
{
	BoxCollider2D::BoxCollider2D()
		: mSize(Vector2(100.0f, 100.0f))
	{
	}
	BoxCollider2D::~BoxCollider2D()
	{
	}
	void BoxCollider2D::Initialize()
	{
	}
	void BoxCollider2D::Update()
	{
	}
	void BoxCollider2D::LateUpdate()
	{
	}
	void BoxCollider2D::Render(HDC hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Vector2 offset = GetOffset();

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		HPEN greenPen = (HPEN)CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

		Rectangle(hdc, pos.x + offset.x
			, pos.y + offset.y
			, pos.x + offset.x + mSize.x
			, pos.y + offset.y + mSize.y);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);

		DeleteObject(greenPen);
	}
}