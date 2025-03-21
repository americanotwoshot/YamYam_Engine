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
		// �ڽ� �����带 ���ξ����忡 ���Խ��� ���ξ����尡 ����Ǳ� ������ block
		mResourceLoad->join();

		// ���ξ������ �и����� �������� ������� �
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
