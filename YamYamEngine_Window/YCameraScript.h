#pragma once
#include "..\\YamYamEngine_SOURCE\\YScript.h"
#include "..\\YamYamEngine_SOURCE\\YTransform.h"

namespace yam
{
	class CameraScript : public Script
	{
	public:
		CameraScript();
		~CameraScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}

