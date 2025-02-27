#pragma once

namespace yam::enums
{
	enum class eLayerType
	{
		None,
		BackGround,
		// tree
		Player,
		UI,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
	};
}