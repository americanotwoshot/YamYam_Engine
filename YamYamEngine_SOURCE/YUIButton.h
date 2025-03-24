#pragma once
#include "YUIBase.h"
#include "YTexture.h"

namespace yam
{
	class UIButton : public UIBase
	{
	public:
		UIButton();
		~UIButton();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnUpdate() override;
		virtual void OnLateUpdate() override;
		virtual void OnRender() override;
		virtual void OnClear() override;

		virtual void ButtonClick();

	private:
		Event mOnClick;
	};
}