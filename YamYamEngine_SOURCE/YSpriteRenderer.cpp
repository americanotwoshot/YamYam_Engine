#include "YSpriteRenderer.h"
#include "YTransform.h"
#include "YGameObject.h"
#include "YTexture.h"
#include "YRenderer.h"
#include "YResources.h"

namespace yam
{
	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mSprite(nullptr)
		, mMaterial(nullptr)
		, mMesh(nullptr)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
		mMesh = Resources::Find<Mesh>(L"RectMesh");
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}
	void SpriteRenderer::Render()
	{
		// VB, IB, InputLayout : 정점 정보 바인드
		if (mMesh)
			mMesh->Bind();
		// 셰이더 바인드
		if (mMaterial)
			mMaterial->BindShader();
		// 텍스쳐 바인드
		if (mSprite)
			mSprite->Bind(eShaderStage::PS, (UINT)eTextureType::Sprite);

		if (mMesh)
			graphics::GetDevice()->DrawIndexed(mMesh->GetIndexCount(), 0, 0);
	}
}