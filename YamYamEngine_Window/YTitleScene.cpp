#include "YTitleScene.h"
#include "YPlayer.h"
#include "YTransform.h"
#include "YSpriteRenderer.h"
#include "YInput.h"
#include "YSceneManager.h"
#include "YObject.h"

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
		//Player* bg = object::Instantiate<Player>
		//	(enums::eLayerType::BackGround, math::Vector2(100.0f, 100.0f));
		//SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		//sr->ImageLoad(L"C:\\Users\\User\\source\\repos\\YamYam\\YamYamEngine\\Resources\\TitleImage.jpg");

		//Player* tx = object::Instantiate<Player>
		//	(enums::eLayerType::UI);
		//SpriteRenderer* txSR = tx->AddComponent<SpriteRenderer>();
		//txSR->SetText(L"Title Scene", 200.0f, 100.0f);
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
	void TitleScene::Render()
	{
		Scene::Render();
	}
}