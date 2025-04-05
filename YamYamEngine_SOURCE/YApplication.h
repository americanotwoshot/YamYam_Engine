#pragma once
#include "CommonInclude.h"
#include "YGameObject.h"
#include "YGraphicDevice_DX11.h"

namespace yam
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, int width, int height);
		void InitializeWindow(HWND hwnd);
		void AdjustWindowRect(HWND hwnd, int width, int height);
		void ResizeGraphicDevice();
		void InitializeEtc();

		void Run();
		void Close();

		void Update();
		void LateUpdate();
		void Render();
		void Present();
		void Destroy();
		void Release();

		HWND GetHwnd() const { return mHwnd; }
		HDC GetHdc() const { return mHdc; }
		UINT GetWidth() const { return mWidth; }
		UINT GetHeight() const { return mHeight; }

		bool IsLoaded() const { return mbLoaded; }
		void IsLoaded(bool load) { mbLoaded = load; }
		bool IsRunning() const { return mbRunning; }

	private:
		bool mbLoaded;
		bool mbRunning;
		std::unique_ptr<graphics::GraphicDevice_DX11> mGraphicDevice;

		HWND mHwnd;
		HDC mHdc;

		// window size
		UINT mWindowWidth;
		UINT mWindowHeight;

		// client size
		UINT mWidth;
		UINT mHeight;

		// window position
		UINT mX, mY;
	};
}


