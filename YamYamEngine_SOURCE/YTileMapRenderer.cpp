#include "YTileMapRenderer.h"
#include "YTransform.h"
#include "YGameObject.h"
#include "YTexture.h"
#include "YRenderer.h"

namespace yam
{
	Vector2 TileMapRenderer::TileSize = Vector2::One;

	TileMapRenderer::TileMapRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(3.0f, 3.0f)
		, mIndex(Vector2::Zero)
		, mTileSize(Vector2(16.0f, 16.0f))
	{
		TileSize = mTileSize * mSize;
	}
	TileMapRenderer::~TileMapRenderer()
	{
	}

	void TileMapRenderer::Initialize()
	{
	}
	void TileMapRenderer::Update()
	{
	}
	void TileMapRenderer::LateUpdate()
	{
	}
	void TileMapRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();
		pos = renderer::mainCamera->CalculatePosition(pos);

		if (mTexture->GetTextureType()
			== graphics::Texture::eTextureType::Bmp)
		{
			if (mTexture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc
					, pos.x, pos.y
					, mTileSize.x * mSize.x * scale.x
					, mTileSize.y * mSize.y * scale.y
					, mTexture->GetHdc()
					, mIndex.x * mTileSize.x
					, mIndex.y * mTileSize.y
					, mTileSize.x
					, mTileSize.y
					, func);
			}
			else
			{
				TransparentBlt(hdc
					, pos.x, pos.y
					, mTileSize.x * mSize.x * scale.x
					, mTileSize.y * mSize.y * scale.y
					, mTexture->GetHdc()
					, mIndex.x * mTileSize.x
					, mIndex.y * mTileSize.y
					, mTileSize.x
					, mTileSize.y
					, RGB(255, 0, 255));
			}
		}
		//else if (mTexture->GetTextureType()
		//	== graphics::Texture::eTextureType::Png)
		//{
		//	// 원하는 픽셀을 투명화 시킬때
		//	Gdiplus::ImageAttributes imgAtt = {};

		//	// 투명화 시킬 픽셀의 색 범위
		//	imgAtt.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));

		//	Gdiplus::Graphics graphics(hdc);

		//	graphics.TranslateTransform(pos.x, pos.y);
		//	graphics.RotateTransform(rot);
		//	graphics.TranslateTransform(-pos.x, -pos.y);

		//	graphics.DrawImage(mTexture->GetImage()
		//		, Gdiplus::Rect
		//		(
		//			pos.x, pos.y
		//			, mTexture->GetWidth() * mSize.x * scale.x
		//			, mTexture->GetHeight() * mSize.y * scale.y
		//		)
		//		, 0, 0
		//		, mTexture->GetWidth(), mTexture->GetHeight()
		//		, Gdiplus::UnitPixel
		//		, nullptr);

		//	//Gdiplus::Graphics graphics(hdc);
		//	//graphics.DrawImage(mTexture->GetImage(), 
		//	//	Gdiplus::Rect(pos.x, pos.y
		//	//		, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
		//}

		//Gdiplus::Graphics graphics(hdc);
		//graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));


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
}