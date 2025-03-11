#pragma once
#include "CommonInclude.h"
#include "YComponent.h"

namespace yam 
{
	using namespace enums;
	class GameObject
	{
	public:
		//friend void object::Destroy(GameObject* obj);

		enum class eState
		{
			Active,
			Paused,
			Dead,
			End
		};

		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);

			mComponents[(UINT)comp->GetType()] = comp;

			return comp;
		}
		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents) 
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}

			return component;
		}

		void SetActive(bool power)
		{
			if (power == true) mState = eState::Active;
			if (power == false) mState = eState::Paused;
		}
		eState GetState() { return mState; }
		bool IsActive() { return mState == eState::Active; }
		bool IsDead() { return mState == eState::Dead; }
		void Death() { mState = eState::Dead; }
		void SetLayerType(eLayerType type) { mLayerType = type; }
		eLayerType GetLayerType() { return mLayerType; }

	private:
		void initializeTransform();

	private:
		eState mState;
		std::vector<Component*> mComponents;
		eLayerType mLayerType;
	};
}

