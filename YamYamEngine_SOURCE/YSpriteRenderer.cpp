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
		// VB, IB, InputLayout : ���� ���� ���ε�
		if (mMesh)
			mMesh->Bind();
		// ���̴� ���ε�
		if (mMaterial)
			mMaterial->BindShader();
		// �ؽ��� ���ε�
		if (mSprite)
			mSprite->Bind(eShaderStage::PS, (UINT)eTextureType::Sprite);

		if (mMesh)
			graphics::GetDevice()->DrawIndexed(mMesh->GetIndexCount(), 0, 0);
	}
}