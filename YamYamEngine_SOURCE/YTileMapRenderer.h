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
		void Render() override;

		Vector2 GetIndex() const { return mIndex; }
		void SetTexture(graphics::Texture* texture) { mTexture = texture; }
		void SetSize(Vector2 size) { mSize = size; }
		void SetIndex(Vector2 index) { mIndex = index; }

	public:
		static Vector2 TileSize;
		static Vector2 OriginTileSize;
		static Vector2 SelectedIndex;

	private:
		Vector2 mTileSize;
		graphics::Texture* mTexture;
		Vector2 mSize;
		Vector2 mIndex;
	};
}

