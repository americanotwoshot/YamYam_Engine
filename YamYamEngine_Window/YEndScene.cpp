#include "YEndScene.h"
#include "YPlayer.h"
#include "YTransform.h"
#include "YSpriteRenderer.h"
#include "YInput.h"
#include "YObject.h"

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
		//Player* bg = object::Instantiate<Player>
		//	(enums::eLayerType::BackGround, math::Vector2(100.0f, 100.0f));
		//SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		//sr->ImageLoad(L"C:\\Users\\User\\source\\repos\\YamYam\\YamYamEngine\\Resources\\EndImage.jpg");

		//Player* tx = object::Instantiate<Player>
		//	(enums::eLayerType::UI);
		//SpriteRenderer* txSR = tx->AddComponent<SpriteRenderer>();
		//txSR->SetText(L"Ending Scene", 200.0f, 100.0f);
	}
	void EndScene::Update()
	{
		Scene::Update();
	}
	void EndScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void EndScene::Render()
	{
		Scene::Render();
	}
}
