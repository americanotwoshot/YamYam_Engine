#pragma once
#include "guiEditor.h"
#include "guiEditorWindow.h"

namespace gui
{
	class EditorApplication
	{
	public:
		enum class eState
		{
			Disable,
			Active,
			Destroy,
		};

		template <typename T>
		T* GetWindow(const std::wstring& name)
		{
			auto iter = mEditorWindows.find(name);
			if (iter == mEditorWindows.end())
				return nullptr;
		
			return dynamic_cast<T*>(iter->second);
		}

		static bool Initialize();
		static void Update();
		static void OnGUI();
		static void Run();
		static void Release();

		static void OpenProject();
		static void NewScene();
		static void SaveScene();
		static void SaveSceneAs();

	private:
		static bool imGuiInitialize();
		static void imGuiRender();

		static ImGuiWindowFlags mFlag;
		static ImGuiDockNodeFlags mDockspaceFlags;
		static eState mState;
		static bool mFullScreen;

		static std::map<std::wstring, EditorWindow*> mEditorWindows;
	};
}

