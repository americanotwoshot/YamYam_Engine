#include "YLoadingScene.h"
#include "YResources.h"
#include "YTexture.h"
#include "YSceneManager.h"

yam::LoadingScene::LoadingScene()
	: mbLoadCompleted(false)
{
}

yam::LoadingScene::~LoadingScene()
{
	delete mResourceLoad;
	mResourceLoad = nullptr;
}

void yam::LoadingScene::Initialize()
{
	mResourceLoad = new std::thread(&LoadingScene::resourcesLoad
		, this, std::ref(mMutex));
}

void yam::LoadingScene::Update()
{
	if (mbLoadCompleted)
	{
		// 자식 쓰레드를 메인쓰레드에 편입시켜 메인쓰레드가 종료되기 전까지 block
		mResourceLoad->join();

		// 메인쓰레드와 분리시켜 독립적인 쓰레드로 운영
		// mResourceLoad->detach();

		SceneManager::LoadScene(L"PlayScene");
	}
}

void yam::LoadingScene::LateUpdate()
{
}

void yam::LoadingScene::Render(HDC hdc)
{
}

void yam::LoadingScene::OnEnter()
{
}

void yam::LoadingScene::OnExit()
{
}

void yam::LoadingScene::resourcesLoad(std::mutex& m)
{
	m.lock();
	{
		Resources::Load<graphics::Texture>(L"Map",
			L"..\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"Player",
			L"..\\Resources\\Player.bmp");
		Resources::Load<graphics::Texture>(L"Cat",
			L"..\\Resources\\ChickenAlpha.bmp");
		Resources::Load<graphics::Texture>(L"SpringFloor",
			L"..\\Resources\\SpringFloor.bmp");
		Resources::Load<graphics::Texture>(L"HPBAR",
			L"..\\Resources\\HPBAR.bmp");
		Resources::Load<graphics::Texture>(L"PixelMap",
			L"..\\Resources\\PixelMap.bmp");
	}
	m.unlock();

	mbLoadCompleted = true;
}
