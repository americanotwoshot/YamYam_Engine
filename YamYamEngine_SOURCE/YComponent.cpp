#include "YComponent.h"

namespace yam
{
	Component::Component(enums::eComponentType type)
		: mType(type)
		, mOwner(nullptr)
	{
	}
	Component::~Component()
	{
	}
	void Component::Initialize()
	{
	}
	void Component::Update()
	{
	}
	void Component::LateUpdate()
	{
	}
	void Component::Render(HDC hdc)
	{
	}
}
