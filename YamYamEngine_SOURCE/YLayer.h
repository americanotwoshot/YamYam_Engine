#pragma once
#include "YEntity.h"
#include "CommonInclude.h"
#include "YGameObject.h"

namespace yam
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		void AddGameObject(GameObject* gameObject);

		const std::vector<GameObject*> GetGameObjects() { return mGameObjects; }

	private:
		//eLayerType mType;
		std::vector<GameObject*> mGameObjects;
	};

	typedef std::vector<GameObject*>::iterator GameObjectIterator;
}

