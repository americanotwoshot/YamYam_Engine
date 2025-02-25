#include "YSpriteRenderer.h"
#include "YTransform.h"
#include "YGameObject.h"

namespace yam
{
	SpriteRenderer::SpriteRenderer()
		: mImage(nullptr)
		, mWidth(100.0f)
		, mHeight(100.0f)
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
		Transform* tr = GetOwner()->GetComponent<Transform>();
		yam::math::Vector2 pos = tr->GetPosition();

		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));

		//// �Ķ� �귯�� ���� �� �Ҵ�(���� ���� ��)
		//HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		//HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		//// ���� �� ���� �� �Ҵ�(���� ��)
		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		//Transform* tr = GetOwner()->GetComponent<Transform>();

		//// �簢�� ����
		//Rectangle(hdc, tr->GetPositionX(), tr->GetPositionY(),
		//	tr->GetPositionX() + mWidth, tr->GetPositionY() + mHeight);

		//SelectObject(hdc, oldBrush);
		//DeleteObject(brush);
		//SelectObject(hdc, oldPen);
		//DeleteObject(redPen);

		// �� ����
		//Ellipse(hdc, 200, 100, 300, 200);

		// ���� ������Ʈ : �⺻���� ���� ���Ǵ� GDI ������Ʈ���� �̸� ������.
		//HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
		//oldBrush = (HBRUSH)SelectObject(hdc, grayBrush);
		//Rectangle(hdc, 400, 400, 500, 500);
		//SelectObject(hdc, oldBrush);


	}
	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		mImage = Gdiplus::Image::FromFile(path.c_str());
		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}
}