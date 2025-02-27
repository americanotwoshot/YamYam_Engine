#pragma once
#include "..\\YamYamEngine_SOURCE\\YResources.h"
#include "..\\YamYamEngine_SOURCE\\YTexture.h"

namespace yam
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG",
			L"C:\\Users\\User\\source\\repos\\YamYam\\YamYamEngine\\Resources\\playImage.jpeg");
	}
}