#include "YTile.h"
#include "YInput.h"
#include "YTransform.h"
#include "YTime.h"
#include "YTileMapRenderer.h"

namespace yam
{
	void Tile::Initialize()
	{
		GameObject::Initialize();
	}
	void Tile::Update()
	{
		GameObject::Update();
	}
	void Tile::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Tile::Render()
	{
		GameObject::Render();
	}

	void Tile::SetPosition(int x, int y)
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos;
		pos.x = x * TileMapRenderer::TileSize.x;
		pos.y = y * TileMapRenderer::TileSize.y;
		tr->SetPosition(pos);
	}
}