#include "YTileMapRenderer.h"
#include "YTransform.h"
#include "YGameObject.h"
#include "YTexture.h"
#include "YRenderer.h"

namespace yam
{
	Vector2 TileMapRenderer::TileSize = Vector2::One;
	Vector2 TileMapRenderer::OriginTileSize = Vector2::One;
	Vector2 TileMapRenderer::SelectedIndex = Vector2(-1.0f,-1.0f);

	TileMapRenderer::TileMapRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(3.0f, 3.0f)
		, mIndex(Vector2::Zero)
		, mTileSize(Vector2(16.0f, 16.0f))
	{
		TileSize = mTileSize * mSize;
		OriginTileSize = mTileSize;
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
	void TileMapRenderer::Render()
	{
		if (mTexture == nullptr)
			assert(false);

		//Transform* tr = GetOwner()->GetComponent<Transform>();
		//Vector2 pos = tr->GetPosition();
		//float rot = tr->GetRotation();
		//Vector2 scale = tr->GetScale();
		//pos = renderer::mainCamera->CalculatePosition(pos);

		//if (mTexture->GetTextureType()
		//	== graphics::Texture::eTextureType::Bmp)
		//{
		//	if (mTexture->IsAlpha())
		//	{
		//		BLENDFUNCTION func = {};
		//		func.BlendOp = AC_SRC_OVER;
		//		func.BlendFlags = 0;
		//		func.AlphaFormat = AC_SRC_ALPHA;
		//		func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

		//		AlphaBlend(hdc
		//			, pos.x, pos.y
		//			, mTileSize.x * mSize.x * scale.x
		//			, mTileSize.y * mSize.y * scale.y
		//			, mTexture->GetHdc()
		//			, mIndex.x * mTileSize.x
		//			, mIndex.y * mTileSize.y
		//			, mTileSize.x
		//			, mTileSize.y
		//			, func);
		//	}
		//	else
		//	{
		//		TransparentBlt(hdc
		//			, pos.x, pos.y
		//			, mTileSize.x * mSize.x * scale.x
		//			, mTileSize.y * mSize.y * scale.y
		//			, mTexture->GetHdc()
		//			, mIndex.x * mTileSize.x
		//			, mIndex.y * mTileSize.y
		//			, mTileSize.x
		//			, mTileSize.y
		//			, RGB(255, 0, 255));
		//	}
		//}
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

	}
}