#pragma once
#include "..\\YamYamEngine_SOURCE\\YGameObject.h"

namespace yam
{
	class Floor : public GameObject
	{
	public:
		Floor();
		~Floor();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:

	};
}
