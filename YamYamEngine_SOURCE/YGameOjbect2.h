#pragma once
#include "commonInclude.h"

namespace yam
{
	class GameOjbect2
	{
	public:
		GameOjbect2();
		~GameOjbect2();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x; mY = y;
		}

	private:
		float mX;
		float mY;
	};
}

