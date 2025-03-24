#include "YApplication.h"
#include "YInput.h"
#include "YTime.h"
#include "YRenderer.h"
#include "YSceneManager.h"
#include "YResources.h"
#include "YCollisionManager.h"
#include "YUIManager.h"
#include "YFmod.h"

namespace yam 
{
	Application::Application() 
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		initializeEtc();

		mGraphicDevice = std::make_unique<graphics::GraphicDevice_DX11>();
		renderer::Initialize();
		mGraphicDevice->Initialize();

		Fmod::Initialize();
		CollisionManager::Initialize();
		UIManager::Initialize();
		SceneManager::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();

		Destroy();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();
		CollisionManager::Update();
		UIManager::Update();
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		CollisionManager::LateUpdate();
		UIManager::LateUpdate();
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		//clearRenderTarget();
		mGraphicDevice->Draw();

		Time::Render();
		CollisionManager::Render();
		UIManager::Render();
		SceneManager::Render();

		//copyRenderTarget(mBackHdc, mHdc);
	}

	void Application::Destroy()
	{
		SceneManager::Destroy();
	}

	void Application::Release()
	{
		SceneManager::Release();
		UIManager::Release();
		Resources::Release();

		renderer::Release();
	}

	void Application::clearRenderTarget()
	{
		HBRUSH grayBrush = (HBRUSH)CreateSolidBrush(RGB(128,128,128));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, grayBrush);

		::Rectangle(mBackHdc, -1, -1, 1601, 901);

		(HBRUSH)SelectObject(mBackHdc, oldBrush);
		DeleteObject(grayBrush);
	}
	void Application::copyRenderTarget(HDC src, HDC dst) {
		BitBlt(dst, 0, 0, mWidth, mHeight,
			src, 0, 0, SRCCOPY);
	}
	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0,
			rect.right - rect.left, rect.bottom - rect.top, 0);
		ShowWindow(mHwnd, true);
	}
	void Application::createBuffer(UINT width, UINT height)
	{
		// 윈도우 해상도에 맞는 백버퍼 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// 새로 생성한 백버퍼를 가르킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}
	void Application::initializeEtc()
	{

		Input::Initialize();
		Time::Initialize();
	}
}