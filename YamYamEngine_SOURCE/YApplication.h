#pragma once
#include "CommonInclude.h"
#include "YGameObject.h"
#include "YGameOjbect2.h"

namespace yam
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		// 플레이어
		GameObject mPlayer;

		// 다른 플레이어
		GameOjbect2 mBox;
	};
}


