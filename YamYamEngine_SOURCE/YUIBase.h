#pragma once
#include "YEntity.h"

namespace yam
{
	using namespace enums;
	class UIBase : public Entity
	{
	public:
		UIBase();
		~UIBase();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void Active();
		void InActive();
		
		void UIClear();

		virtual void OnInit();
		virtual void OnActive();
		virtual void OnInActive();
		virtual void OnUpdate();
		virtual void OnClear();

		eUIType GetType() { return mType; }
		void SetFullScreen(bool enable) { mbFullScreen = enable; }
		bool IsFullScreen() { return mbFullScreen; }

	private:
		eUIType mType;
		bool mbFullScreen;
		bool mbEnabled;
	};
}
