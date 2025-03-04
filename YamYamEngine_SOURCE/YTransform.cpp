#include "YTransform.h"
#include "YInput.h"
#include "YTime.h"

namespace yam
{
	Transform::Transform()
		: Component(enums::eComponentType::Transform)
		, mPosition(math::Vector2(0, 0))
		, mScale(Vector2::One)
		, mRotation(0.0f)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{
	}
	void Transform::Update()
	{
	}
	void Transform::LateUpdate()
	{
	}
	void Transform::Render(HDC hdc)
	{
	}
}