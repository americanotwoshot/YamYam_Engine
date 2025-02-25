#include "YPlayScene.h"
#include "YGameObject.h"
#include "YPlayer.h"
#include "YTransform.h"
#include "YSpriteRenderer.h"

namespace yam
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		{
			Player* pl = new Player();
			Transform* tr = pl->AddComponent<Transform>();
			tr->SetPosition(500, 500);
			tr->SetName(L"TR");

			SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();
			sr->SetSize(100, 100);
			sr->SetName(L"SR");

			AddGameObject(pl);
		}
		{
			Player* pl = new Player();
			Transform* tr = pl->AddComponent<Transform>();
			tr->SetPosition(300, 450);
			tr->SetName(L"TR");

			SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();
			sr->SetSize(200, 200);
			sr->SetName(L"SR");

			AddGameObject(pl);
		}
		{
			Player* pl = new Player();
			Transform* tr = pl->AddComponent<Transform>();
			tr->SetPosition(100, 650);
			tr->SetName(L"TR");

			SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();
			sr->SetSize(50, 50);
			sr->SetName(L"SR");

			AddGameObject(pl);
		}
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}