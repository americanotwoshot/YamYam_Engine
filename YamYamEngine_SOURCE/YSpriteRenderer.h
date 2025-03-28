#pragma once
#include "YEntity.h"
#include "YComponent.h"
#include "YTexture.h"
#include "YMaterial.h"
#include "YMesh.h"

namespace yam
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void SetSprite(graphics::Texture* sprite) { mSprite = sprite; }
		void SetMaterial(Material* material) { mMaterial = material; }
		void SetMesh(Mesh* mesh) { mMesh = mesh; }

	private:
		graphics::Texture* mSprite;
		Material* mMaterial;
		Mesh* mMesh;
	};
}

