#pragma once
#include "guiEditor.h"
#include "guiEditorWindow.h"

namespace gui
{
	class EditorApplication
	{
	public:
		static bool Initialize();
		static void Update();
		static void OnGUI();
		static void Run();
		static void Release();

	private:
		static bool imGuiInitialize();
		static void imGuiRender();
	};
}

