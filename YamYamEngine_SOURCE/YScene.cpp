#include "YScene.h"
#include "YCollisionManager.h"
#include "YSceneManager.h"

namespace yam
{
	Scene::Scene()
		:mLayers{}
	{
		createLayers();
	}
	Scene::~Scene()
	{
		for (Layer* layer : mLayers)
		{
			delete layer;
			layer = nullptr;
		}
	}

	void Scene::Initialize()
	{
		const std::wstring& sceneName = GetName();
		SceneManager::SetActiveScene(sceneName);
	}
	void Scene::Update()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->LateUpdate();
		}
	}
	void Scene::Render()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Render();
		}
	}

	void Scene::Destroy()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Destroy();
		}
	}

	void Scene::AddGameObject(GameObject* gameObj, const enums::eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}
	void Scene::EraseGameObject(GameObject* gameObj)
	{
		eLayerType layerType = gameObj->GetLayerType();
		mLayers[(UINT)layerType]->EraseGameObject(gameObj);
	}

	void Scene::OnEnter()
	{

	}
	void Scene::OnExit()
	{
		CollisionManager::Clear();
	}

	void Scene::createLayers()
	{
		mLayers.resize((UINT)enums::eLayerType::Max);
		std::for_each(mLayers.begin(), mLayers.end(),
			[](Layer*& layer) {
				layer = new Layer;
			});
	}
}