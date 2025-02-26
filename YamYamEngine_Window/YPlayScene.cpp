#include "YPlayScene.h"
#include "YGameObject.h"
#include "YPlayer.h"
#include "YTransform.h"
#include "YSpriteRenderer.h"
#include "YInput.h"
#include "YSceneManager.h"
#include "YObject.h"

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
		//bg = new Player();
		//Transform* tr = bg->AddComponent<Transform>();
		//tr->SetPosition(math::Vector2(500, 500));
		//tr->SetName(L"TR");

		//SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		//sr->SetName(L"SR");
		//sr->ImageLoad(L"C:\\Users\\User\\source\\repos\\YamYam\\YamYamEngine\\Resources\\playImage.jpeg");
		//
		//AddGameObject(bg, eLayerType::BackGround);
		bg = object::Instantiate<Player>
			(enums::eLayerType::BackGround, math::Vector2(100.0f, 100.0f));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->ImageLoad(L"C:\\Users\\User\\source\\repos\\YamYam\\YamYamEngine\\Resources\\playImage.jpeg");
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(math::Vector2(500, 500));
	}
}