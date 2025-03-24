#pragma once
#include "YEntity.h"

namespace yam
{
	class GameObject;
	class Component : public Entity
	{
	public:
		Component(enums::eComponentType type);
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		GameObject* GetOwner() const { return mOwner; }
		enums::eComponentType GetType() const { return mType; }
		void SetOwner(GameObject* onwer) { mOwner = onwer; }

	private:
		GameObject* mOwner;
		enums::eComponentType mType;
	};
}

