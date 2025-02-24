#pragma once
#include "..\\YamYamEngine_SOURCE\\YSceneManager.h"
#include "YPlayScene.h"

namespace yam
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<PlayScene>(L"TitleScene");
		//SceneManager::CreateScene<PlayScene>(L"EndScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}