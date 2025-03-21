#pragma once
#include "..\\YamYamEngine_SOURCE\\YSceneManager.h"
#include "YPlayScene.h"
#include "YTitleScene.h"
#include "YEndScene.h"
#include "YToolScene.h"
#include "YLoadingScene.h"

namespace yam
{
	void LoadScenes()
	{
		SceneManager::CreateScene<LoadingScene>(L"LoadingScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");
		//SceneManager::CreateScene<ToolScene>(L"ToolScene");

		SceneManager::LoadScene(L"LoadingScene");
	}
}