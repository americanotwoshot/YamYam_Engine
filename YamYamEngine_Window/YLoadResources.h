#pragma once
#include "..\\YamYamEngine_SOURCE\\YResources.h"
#include "..\\YamYamEngine_SOURCE\\YTexture.h"

namespace yam
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Map",
			L"..\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"PacMan",
			L"..\\Resources\\img\\pacman\\0.png");
	}
}