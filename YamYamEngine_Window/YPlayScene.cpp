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
		//mPlayer->AddComponent<AudioListener>();

		//PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();
		//BoxCollider2D* plCollider = mPlayer->AddComponent<BoxCollider2D>();
		//CircleCollider2D* plCollider = mPlayer->AddComponent<CircleCollider2D>();
		//plCollider->SetOffset(Vector2(-50.0f, -50.0f));

		//graphics::Texture* playerTexture = Resources::Find<graphics::Texture>(L"Player");
		//Animator* playerAnimator = mPlayer->AddComponent<Animator>();
		//playerAnimator->CreateAnimation(L"Idle", playerTexture
		//	, Vector2(2000.0f, 250.0f), Vector2(250.0f,250.0f), Vector2::Zero, 1, 0.2f);
		//playerAnimator->CreateAnimation(L"FrontGiveWater", playerTexture
		//	, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.2f);
		//playerAnimator->PlayAnimation(L"Idle", false);

		//playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);

		//mPlayer->GetComponent<Transform>()->SetPosition(Vector2(400.0f,250.0f));
		//mPlayer->GetComponent<Transform>()->SetScale(Vector2(0.5f, 0.5f));

		//mPlayer->AddComponent<Rigidbody>();


		// floor
		//Floor* floor = object::Instantiate<Floor>(eLayerType::Floor, Vector2(0.0f, 0.0f));
		//SpriteRenderer* floorSR = floor->AddComponent<SpriteRenderer>();
		//floorSR->SetTexture(Resources::Find<graphics::Texture>(L"PixelMap"));

		//plScript->SetPixelMapTexture(Resources::Find<graphics::Texture>(L"PixelMap"));
		//BoxCollider2D* floorCol = floor->AddComponent<BoxCollider2D>();
		//floorCol->SetSize(Vector2(5.0f, 1.0f));
		//floor->AddComponent<FloorScript>();
		//AudioSource* as = floor->AddComponent<AudioSource>();

		//AudioClip* ac = Resources::Load<AudioClip>(L"BGSound", L"..\\Resources\\Sound\\smw_bonus_game_end.wav");

		//as->SetClip(ac);
		//as->Play();

		// cat
		//Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
		//cat->AddComponent<CatScript>();

		//graphics::Texture* catTexture = Resources::Find<graphics::Texture>(L"Cat");
		//Animator* catAnimator = cat->AddComponent<Animator>();

		//BoxCollider2D* catCollider = cat->AddComponent<BoxCollider2D>();
		////CircleCollider2D* catCollider = cat->AddComponent<CircleCollider2D>();
		//catCollider->SetOffset(Vector2(-50.0f, -50.0f));

		////catAnimator->CreateAnimation(L"DownWalk", catTexture
		////	, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		////catAnimator->CreateAnimation(L"RightWalk", catTexture
		////	, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		////catAnimator->CreateAnimation(L"UpWalk", catTexture
		////	, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		////catAnimator->CreateAnimation(L"LeftWalk", catTexture
		////	, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		////catAnimator->CreateAnimation(L"SitDown", catTexture
		////	, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.5f);
		////catAnimator->CreateAnimation(L"Grooming", catTexture
		////	, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.5f);
		////catAnimator->CreateAnimation(L"LayDown", catTexture
		////	, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.5f);

		////catAnimator->PlayAnimation(L"SitDown", false);
		//
		//catAnimator->CreateAnimationByFolder(L"MushroomIdle", L"..\\Resources\\Mushroom", Vector2::Zero, 0.1f);
		//catAnimator->PlayAnimation(L"MushroomIdle", true);
		//cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		////cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));


		// background
		//GameObject* bg = object::Instantiate<GameObject>
		//	(enums::eLayerType::BackGround);
		//SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		//bgSr->SetSize(Vector2(3.0f, 3.0f));

		//graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Map");
		//bgSr->SetTexture(bgTexture);

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

		graphics::GetDevice()->Draw();
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