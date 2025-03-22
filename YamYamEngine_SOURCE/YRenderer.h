#pragma once
#include "YCamera.h"
#include "YGraphicDevice_DX11.h"
#include "YVertexBuffer.h"

namespace yam::renderer
{
	extern Camera* mainCamera;

	extern std::vector<graphics::Vertex> vertexes;
	extern std::vector<UINT> indices;
	
	extern graphics::VertexBuffer vertexBuffer;
	extern ID3D11Buffer* indexBuffer;
	extern ID3D11Buffer* constantBuffer;

	extern ID3D11InputLayout* inputLayouts;

	void Initialize();
	void Release();
}

