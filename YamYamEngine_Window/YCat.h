#pragma once
#include "..\\YamYamEngine_SOURCE\\YGameObject.h"

namespace yam
{
	class Cat : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}
