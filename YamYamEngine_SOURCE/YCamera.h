#pragma once
#include "YComponent.h"

namespace yam
{
	using namespace yam::math;
	class Camera : public Component
	{
	public:
		enum class eProjectionType
		{
			Perspective,
			Orthographic,
		};

		static Matrix GetGpuViewMatrix() { return ViewMatrix; }
		static Matrix GetGpuProjectionMatrix() { return ProjectionMatrix; }
		static void SetGpuViewMatrix(Matrix matrix) { ViewMatrix = matrix; }
		static void SetGpuProjectionMatrix(Matrix matrix) { ProjectionMatrix = matrix; }

		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void CreateViewMatrix();
		void CreateProjectionMatrix(eProjectionType type);

		Matrix GetViewMatrix() const { return mViewMatrix; }
		Matrix GetProjectionMatrix() const { return mProjectionMatrix; }
		void SetProjectionType(eProjectionType type) { mProjectionType = type; }
		void SetSize(float size) { mSize = size; }

	private:
		static Matrix ViewMatrix;
		static Matrix ProjectionMatrix;

		eProjectionType mProjectionType;

		Matrix mViewMatrix;
		Matrix mProjectionMatrix;
		float mAspectRatio;
		float mNear;
		float mFar;
		float mSize;
	};
}

