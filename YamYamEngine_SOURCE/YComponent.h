#pragma once
#include "YEntity.h"

namespace yam
{
	class GameObject;
	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* onwer) { mOwner = onwer; }
		GameObject* GetOwner() { return mOwner; }

	private:
		GameObject* mOwner;
	};
}

