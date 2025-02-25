#include "YTitleScene.h"

namespace yam
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		for (size_t i = 0; i < 5; i++)
		{
			GameObject* gameObj = new GameObject();
			//gameObj->SetPosition(100 + 300 * i, 600);
			//gameObj->SetSize(50, 50);
			AddGameObject(gameObj);
		}
	}
	void TitleScene::Update()
	{
		Scene::Update();
	}
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}