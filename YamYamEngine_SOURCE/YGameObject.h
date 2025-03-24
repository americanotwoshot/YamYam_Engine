#pragma once
#include "CommonInclude.h"
#include "YComponent.h"

namespace yam 
{
	using namespace enums;
	class GameObject : public Entity
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
		virtual void Render();

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

		eState GetState() const { return mState; }
		eLayerType GetLayerType() const { return mLayerType; }

		bool IsActive() const { return mState == eState::Active; }
		bool IsDead() const { return mState == eState::Dead; }

		void SetActive(bool power)
		{
			if (power == true) mState = eState::Active;
			if (power == false) mState = eState::Paused;
		}
		void Death() { mState = eState::Dead; }
		void SetLayerType(eLayerType type) { mLayerType = type; }

	private:
		void initializeTransform();

	private:
		eState mState;
		std::vector<Component*> mComponents;
		eLayerType mLayerType;
	};
}

