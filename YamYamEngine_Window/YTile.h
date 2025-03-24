#pragma once
#include "..\\YamYamEngine_SOURCE\\YGameObject.h"

namespace yam
{
	class Tile : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void SetPosition(int x, int y);

	private:

	};
}

