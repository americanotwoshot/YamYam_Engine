#include "YRenderer.h"
#include "YGraphicDevice_DX11.h"

#include "YResources.h"
#include "YShader.h"

namespace yam::renderer
{
	Camera* mainCamera = nullptr;

	std::vector<Vertex> vertexes = {};
	std::vector<UINT> indices;

	VertexBuffer vertexBuffer;
	IndexBuffer indexBuffer;
	ConstantBuffer constantBuffer[(UINT)eCBType::End] = {};

	ID3D11InputLayout* inputLayouts = nullptr;
	
	void LoadTriangleMesh()
	{
		renderer::vertexes.resize(3);
		renderer::vertexes[0].pos = Vector3(0.0f, 0.5f, 0.0f);
		renderer::vertexes[0].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		renderer::vertexes[1].pos = Vector3(0.5f, -0.5f, 0.0f);
		renderer::vertexes[1].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		renderer::vertexes[2].pos = Vector3(-0.5f, -0.5f, 0.0f);
		renderer::vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);
	}

	void LoadMeshes()
	{
		LoadTriangleMesh();
	}

	void LoadShaders()
	{
		yam::Resources::Load<graphics::Shader>(L"TriangleShader"
			, L"..\\Shaders_SOURCE\\Triangle");
	}

	void LoadConstantBuffers()
	{
		constantBuffer[(UINT)eCBType::Transform].Create(eCBType::Transform, sizeof(Vector4));
	}

	void Initialize()
	{
		LoadMeshes();
		LoadShaders();
		LoadConstantBuffers();
	}

	void Release()
	{
		inputLayouts->Release();
	}
}