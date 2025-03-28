#include "YLoadingScene.h"
#include "YResources.h"
#include "YTexture.h"
#include "YSceneManager.h"
#include "YApplication.h"
#include "YTitleScene.h"
#include "YPlayScene.h"
#include "YRenderer.h"

extern yam::Application application;

yam::LoadingScene::LoadingScene()
	: mbLoadCompleted(false)
	, mResourceLoad()
	, mMutex()
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

}

void yam::LoadingScene::LateUpdate()
{
}

void yam::LoadingScene::Render()
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

void yam::LoadingScene::OnEnter()
{
}

void yam::LoadingScene::OnExit()
{
}

void yam::LoadingScene::resourcesLoad(std::mutex& m)
{
	while (true)
	{
		if (application.IsLoaded() == true)
			break;
	}

	m.lock();
	{
		Resources::Load<graphics::Texture>(L"Player",
			L"..\\Resources\\CloudOcean.png");

		renderer::Initialize();

		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
	}
	m.unlock();

	mbLoadCompleted = true;
}
