#pragma once
#include "guiEntity.h"

namespace gui
{
	class EditorWindow : public Entity
	{
	public:
		enum class eState
		{
			Disable,
			Active,
			Destroy,
		};

		EditorWindow();
		virtual ~EditorWindow();

		virtual void Initialize();
		virtual void Update();
		virtual void OnGUI();
		virtual void Run();
		virtual void OnEnable();
		virtual void OnDisable();
		virtual void OnDestroy();

		ImGuiWindowFlags GetFlag() const { return mFlag; }
		eState GetState() const { return mState; }
		ImVec2 GetSize() const { return mSize; }
		void SetState(eState state) { mState = state; }
		void SetSize(ImVec2 size) { mSize = size; }

	private:
		ImGuiWindowFlags mFlag;
		eState mState;
		ImVec2 mSize;
	};
}

