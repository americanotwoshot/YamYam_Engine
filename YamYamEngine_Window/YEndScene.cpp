#include "YEndScene.h"

namespace yam
{
	EndScene::EndScene()
	{
	}
	EndScene::~EndScene()
	{
	}
	void EndScene::Initialize()
	{
		for (size_t i = 0; i < 3; i++)
		{
			GameObject* gameObj = new GameObject();
			//gameObj->SetPosition(500 + 400 * i, 600);
			//gameObj->SetSize(200, 200);
			AddGameObject(gameObj);
		}
	}
	void EndScene::Update()
	{
		Scene::Update();
	}
	void EndScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void EndScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
