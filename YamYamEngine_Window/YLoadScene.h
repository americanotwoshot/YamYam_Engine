#pragma once
#include "..\\YamYamEngine_SOURCE\\YSceneManager.h"
#include "YPlayScene.h"
#include "YTitleScene.h"
#include "YEndScene.h"

namespace yam
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<EndScene>(L"EndScene");

		SceneManager::LoadScene(L"EndScene");
	}
}