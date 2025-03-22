#pragma once
#include "YCamera.h"
#include "YGraphicDevice_DX11.h"
#include "YVertexBuffer.h"
#include "YIndexBuffer.h"

using namespace yam::math;
using namespace yam::graphics;

namespace yam::renderer
{
	extern Camera* mainCamera;

	extern std::vector<Vertex> vertexes;
	extern std::vector<UINT> indices;
	
	extern VertexBuffer vertexBuffer;
	extern IndexBuffer indexBuffer;
	extern ID3D11Buffer* constantBuffer;

	extern ID3D11InputLayout* inputLayouts;

	void Initialize();
	void Release();
}

