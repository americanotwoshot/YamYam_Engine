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

		//// 파랑 브러쉬 생성 및 할당(도형 내부 색)
		//HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		//HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		//// 빨강 선 생성 및 할당(도형 선)
		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		//Transform* tr = GetOwner()->GetComponent<Transform>();

		//// 사각형 생성
		//Rectangle(hdc, tr->GetPositionX(), tr->GetPositionY(),
		//	tr->GetPositionX() + mWidth, tr->GetPositionY() + mHeight);

		//SelectObject(hdc, oldBrush);
		//DeleteObject(brush);
		//SelectObject(hdc, oldPen);
		//DeleteObject(redPen);

		// 원 생성
		//Ellipse(hdc, 200, 100, 300, 200);

		// 스톡 오브젝트 : 기본으로 자주 사용되는 GDI 오브젝트들을 미리 만들어둠.
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