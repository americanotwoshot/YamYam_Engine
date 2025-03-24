#pragma once
#include "..\\YamYamEngine_SOURCE\\YScene.h"

namespace yam
{
	class EndScene : public Scene
	{
	public:
		EndScene();
		~EndScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;
	private:

	};
}


