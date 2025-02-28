#pragma once
#include "..\\YamYamEngine_SOURCE\\YScript.h"

namespace yam
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}

