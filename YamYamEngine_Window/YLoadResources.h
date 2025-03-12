#pragma once
#include "..\\YamYamEngine_SOURCE\\YResources.h"
#include "..\\YamYamEngine_SOURCE\\YTexture.h"

namespace yam
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Map",
			L"..\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"Player",
			L"..\\Resources\\Player.bmp");
		Resources::Load<graphics::Texture>(L"Cat",
			L"..\\Resources\\ChickenAlpha.bmp");
		Resources::Load<graphics::Texture>(L"SpringFloor",
			L"..\\Resources\\SpringFloor.bmp");
	}
}