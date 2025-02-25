#include "YTitleScene.h"
#include "YPlayer.h"
#include "YTransform.h"
#include "YSpriteRenderer.h"

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
		Player* pl = new Player();
		Transform* tr = pl->AddComponent<Transform>();
		tr->SetPosition(math::Vector2(0.0f, 0.0f));
		tr->SetName(L"TR");

		SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\Users\\User\\source\\repos\\YamYam\\YamYamEngine\\Resources\\TitleImage.jpg");

		Scene::AddGameObject(pl);
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