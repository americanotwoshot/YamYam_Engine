#include "YToolScene.h"
#include "YObject.h"
#include "YTile.h"
#include "YTileMapRenderer.h"
#include "YResources.h"
#include "YTexture.h"
#include "YCamera.h"
#include "YRenderer.h"

namespace yam
{
	ToolScene::ToolScene()
	{
	}
	ToolScene::~ToolScene()
	{
	}

	void ToolScene::Initialize()
	{
		// main Camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(343.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		Tile* tile = object::Instantiate<Tile>(eLayerType::Tile);
		TileMapRenderer* tmr = tile->AddComponent<TileMapRenderer>();
		tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));

		Scene::Initialize();
	}
	void ToolScene::Update()
	{
		Scene::Update();
	}
	void ToolScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(hdc, (16 * 3) * i, 0, NULL);
			LineTo(hdc, (16 * 3) * i, 1000);
		}

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(hdc, 0, (16 * 3) * i, NULL);
			LineTo(hdc, 1000, (16 * 3) * i);
		}
	}

	void ToolScene::OnEnter()
	{
		Scene::OnEnter();
	}
	void ToolScene::OnExit()
	{
		Scene::OnExit();
	}
}