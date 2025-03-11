#include "YLayer.h"

namespace yam
{
	Layer::Layer()
		:mGameObjects{}
	{
	
	}
	Layer::~Layer() 
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			delete gameObj;
			gameObj = nullptr;
		}
	}

	void Layer::Initialize()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Initialize();
		}
	}
	void Layer::Update()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			if (gameObj->IsActive() == false)
				continue;

			gameObj->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			if (gameObj->IsActive() == false)
				continue;

			gameObj->LateUpdate();
		}
	}
	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			if (gameObj->IsActive() == false)
				continue;

			gameObj->Render(hdc);
		}
	}

	void Layer::Destroy()
	{
		std::vector<GameObject*> deleteObjects = {};
		findDeadGameObjects(deleteObjects);
		eraseDeadGameObject();
		deleteDeadGameObjects(deleteObjects);
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		mGameObjects.push_back(gameObject);
	}
	void Layer::EraseGameObject(GameObject* gameObject)
	{
		std::erase_if(mGameObjects,
			[=](GameObject* gameObj)
			{
				return gameObj == gameObject;
			});
	}

	void Layer::findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj->IsDead() == true)
				gameObjs.push_back(gameObj);
		}
	}
	void Layer::eraseDeadGameObject()
	{
		std::erase_if(mGameObjects,
			[](GameObject* gameObj) 
			{
				return gameObj->IsDead();
			});
	}
	void Layer::deleteDeadGameObjects(std::vector<GameObject*>& deleteObjs)
	{
		for (GameObject* obj : deleteObjs)
		{
			delete obj;
			obj = nullptr;
		}
	}

}