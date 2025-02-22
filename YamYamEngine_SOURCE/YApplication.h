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

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		// �÷��̾�
		GameObject mPlayer;

		// �ٸ� �÷��̾�
		GameOjbect2 mBox;
	};
}


