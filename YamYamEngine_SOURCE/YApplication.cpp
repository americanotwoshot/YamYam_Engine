#include "YApplication.h"
#include "YInput.h"
#include "YTime.h"

namespace yam 
{
	Application::Application() 
		: mHwnd(nullptr)
		, mHdc(nullptr)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		mPlayer.SetPosition(0, 0);
		mBox.SetPosition(0, 0);

		Input::Initialize();
		Time::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		mPlayer.Update();
		mBox.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		Time::Render(mHdc);

		mPlayer.Render(mHdc);
		mBox.Render(mHdc);
	}
}