#include "YPlayScene.h"
#include "YGameObject.h"
#include "YPlayer.h"
#include "YTransform.h"
#include "YSpriteRenderer.h"
#include "YInput.h"
#include "YSceneManager.h"
#include "YUIManager.h"
#include "YObject.h"
#include "YTexture.h"
#include "YResources.h"
#include "YPlayerScript.h"
#include "YCamera.h"
#include "YRenderer.h"
#include "YAnimator.h"
#include "YCat.h"
#include "YCatScript.h"
#include "YBoxCollider2D.h"
#include "YCollisionManager.h"
#include "YCircleCollider2D.h"
#include "YTileMapRenderer.h"
#include "YTile.h"
#include "YRigidbody.h"
#include "YFloor.h"
#include "YFloorScript.h"
#include "YAudioClip.h"
#include "YAudioListener.h"
#include "YAudioSource.h"
#include "YGraphicDevice_DX11.h"
#include "YMaterial.h"

namespace yam
{
	PlayScene::PlayScene()
		: mPlayer(nullptr)
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		//// main Camera
		//GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(343.0f, 442.0f));
		//Camera* cameraComp = camera->AddComponent<Camera>();
		//renderer::mainCamera = cameraComp;
		////camera->AddComponent<PlayerScript>();

		// player
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		object::DontDestroyOnLoad(mPlayer);
		
		SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial"));
		sr->SetSprite(Resources::Find<graphics::Texture>(L"Player"));

		Scene::Initialize();
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
			SceneManager::LoadScene(L"EndScene");
		}
	}
	void PlayScene::Render()
	{
		Scene::Render();
	}

	void PlayScene::OnEnter()
	{
		//CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);
		//CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Floor, true);
	
		//UIManager::Push(eUIType::Button);
	}
	void PlayScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(math::Vector2(500, 500));
		//UIManager::Pop(eUIType::Button);
	}
}