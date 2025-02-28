#include "YSpriteRenderer.h"
#include "YTransform.h"
#include "YGameObject.h"
#include "YTexture.h"
#include "YRenderer.h"

namespace yam
{
	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(math::Vector2::One)
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
		if (mTexture == nullptr)
			assert(false);
		
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos = renderer::mainCamera->CalculatePosition(pos);

		if (mTexture->GetTextureType()
			== graphics::Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y
				, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType()
			== graphics::Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage(), 
				Gdiplus::Rect(pos.x, pos.y
					, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
		}

		//Gdiplus::Graphics graphics(hdc);
		//graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));


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
}