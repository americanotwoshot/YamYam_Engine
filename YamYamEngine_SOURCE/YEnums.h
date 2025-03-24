#pragma once

namespace yam::enums
{
	enum class eComponentType
	{
		Transform,
		Collider,
		Rigidbody,
		Script,
		SpriteRenderer,
		Animator,
		Camera,
		AudioListener,
		AudioSource,
		End,
	};

	enum class eLayerType
	{
		None,
		BackGround,
		Tile,
		// tree
		Animal,
		Player,
		Floor,
		UI,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		Mesh,
		Animation,
		AudioClip,
		Shader,
		Prefab,
		End,
	};

	enum class eColliderType
	{
		Circle2D,
		Rect2D,
		End,
	};

	enum class eUIType
	{
		HpBar,
		Button,
		End,
	};
}