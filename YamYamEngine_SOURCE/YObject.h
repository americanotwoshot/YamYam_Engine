#pragma once
#include "YComponent.h"
#include "YGameObject.h"
#include "YLayer.h"
#include "YScene.h"
#include "YSceneManager.h"
#include "YTransform.h"

namespace yam::object
{
	template <typename T>
	static T* Instantiate(yam::enums::eLayerType type)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(yam::enums::eLayerType type, math::Vector3 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}

	static void Destroy(GameObject* obj)
	{
		obj->Death();
	}

	static void DontDestroyOnLoad(GameObject* gameObject)
	{
		// 현재 씬에서 게임 오브젝트를 지워준다.
		Scene* activeScene = SceneManager::GetActiveScene();
		activeScene->EraseGameObject(gameObject);

		// 해당 게임 오브젝트를 DontDestroyOnLoad 씬으로 넣어준다.
		Scene* dontDestroyOnLoad = SceneManager::GetDontDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(gameObject, gameObject->GetLayerType());
	}
}