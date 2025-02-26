#include "YTitleScene.h"
#include "YPlayer.h"
#include "YTransform.h"
#include "YSpriteRenderer.h"
#include "YInput.h"
#include "YSceneManager.h"

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
		//Player* pl = new Player();
		//Transform* tr = pl->AddComponent<Transform>();
		//tr->SetPosition(math::Vector2(0.0f, 0.0f));
		//tr->SetName(L"TR");

		//SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();
		//sr->SetName(L"SR");
		//sr->ImageLoad(L"C:\\Users\\User\\source\\repos\\YamYam\\YamYamEngine\\Resources\\TitleImage.jpg");

		//Scene::AddGameObject(pl, enums::eLayerType::BackGround);
	}
	void TitleScene::Update()
	{
		Scene::Update();
	}
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);
	}
}