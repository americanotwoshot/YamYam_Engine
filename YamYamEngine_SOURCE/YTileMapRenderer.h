#pragma once
#include "YEntity.h"
#include "YComponent.h"
#include "YTexture.h"

namespace yam
{
	class TileMapRenderer : public Component
	{
	public:
		TileMapRenderer();
		~TileMapRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(graphics::Texture* texture) { mTexture = texture; }
		void SetSize(Vector2 size) { mSize = size; }

	private:
		Vector2 mTileSize;

		graphics::Texture* mTexture;
		Vector2 mSize;
		Vector2 mIndex;
	};
}

