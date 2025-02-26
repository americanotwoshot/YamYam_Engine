#include "YEndScene.h"
#include "YPlayer.h"
#include "YTransform.h"
#include "YSpriteRenderer.h"

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
		//Player* pl = new Player();
		//Transform* tr = pl->AddComponent<Transform>();
		//tr->SetPosition(yam::math::Vector2(0.0f, 0.0f));
		//tr->SetName(L"TR");

		//SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();
		//sr->SetName(L"SR");
		//sr->ImageLoad(L"C:\\Users\\User\\source\\repos\\YamYam\\YamYamEngine\\Resources\\EndImage.jpg");

		//Scene::AddGameObject(pl, enums::eLayerType::BackGround);
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
