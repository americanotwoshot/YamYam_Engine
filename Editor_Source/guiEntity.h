#pragma once
#include "..\\YamYamEngine_SOURCE\\CommonInclude.h"

#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"

#include "ImGuizmo.h"
#include "ImSequencer.h"
#include "ImZoomSlider.h"
#include "ImCurveEdit.h"
#include "GraphEditor.h"

namespace gui
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::string& name) { mName = name; }
		std::string& GetName() { return mName; }

	private:
		std::string mName;
	};
}

