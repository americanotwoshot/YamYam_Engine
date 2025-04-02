#pragma once
#include "YComponent.h"
#include "CommonInclude.h"

namespace yam
{
	using namespace math;
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void Bind();

		Matrix GetWorldMatrix() const { return mWorldMatrix; }

		Vector3 GetPosition() const { return mPosition; }
		Vector3 GetRotation() const { return mRotation; }
		Vector3 GetScale() const { return mScale; }

		void SetPosition(Vector3 position){ mPosition = position; }
		void SetPosition(float x, float y, float z) { mPosition = Vector3(x, y, z); }
		void SetRotation(Vector3 rotation) { mRotation = rotation; }
		void SetRotation(float x, float y, float z) { mRotation = Vector3(x, y, z); }
		void SetScale(Vector3 scale) { mScale = scale; }
		void SetScale(float x, float y, float z) { mScale = Vector3(x, y, z); }

		Vector3 Forward() const { return mForward; }
		Vector3 Right() const { return mRight; }
		Vector3 Up() const { return mUp; }

	private:
		Matrix mWorldMatrix;

		Vector3 mPosition;
		Vector3 mRotation;
		Vector3 mScale;

		Vector3 mForward;
		Vector3 mRight;
		Vector3 mUp;
	};
}

