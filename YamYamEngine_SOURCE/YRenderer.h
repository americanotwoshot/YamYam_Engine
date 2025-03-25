#pragma once
#include "YCamera.h"
#include "YGraphicDevice_DX11.h"

#include "YMesh.h"
#include "YConstantBuffer.h"

using namespace yam::math;
using namespace yam::graphics;

namespace yam::renderer
{
	extern Camera* mainCamera;
	
	extern Mesh* mesh;
	extern ConstantBuffer constantBuffer[(UINT)eCBType::End];

	extern ID3D11InputLayout* inputLayouts;

	void Initialize();
	void Release();
}

