#pragma once
#include "YEntity.h"
#include "YGameObject.h"
#include "YLayer.h"

namespace yam
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Destroy();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const enums::eLayerType type);
		void EraseGameObject(GameObject* gameObj);
		Layer* GetLayer(enums::eLayerType type) { return mLayers[(UINT)type]; }


	private:
		void createLayers();

	private:
		std::vector<Layer*> mLayers;
	};
}

