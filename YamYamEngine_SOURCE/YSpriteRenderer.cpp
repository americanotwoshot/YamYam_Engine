#include "YSpriteRenderer.h"
#include "YTransform.h"
#include "YGameObject.h"

namespace yam
{
	SpriteRenderer::SpriteRenderer()
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{
		// �Ķ� �귯�� ���� �� �Ҵ�(���� ���� ��)
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		// ���� �� ���� �� �Ҵ�(���� ��)
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		Transform* tr = GetOwner()->GetComponent<Transform>();

		// �簢�� ����
		Rectangle(hdc, tr->GetPositionX(), tr->GetPositionY(),
			tr->GetPositionX() + mWidth, tr->GetPositionY() + mHeight);

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