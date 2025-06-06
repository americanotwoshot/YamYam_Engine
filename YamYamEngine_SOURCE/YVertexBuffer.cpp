#include "YVertexBuffer.h"

namespace yam::graphics
{
	VertexBuffer::VertexBuffer()
	{
	}
	VertexBuffer::~VertexBuffer()
	{
	}

	bool VertexBuffer::Create(const std::vector<Vertex>& vertexes)
	{
		desc.ByteWidth = sizeof(Vertex) * (UINT)vertexes.size();
		desc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER;
		desc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;

		D3D11_SUBRESOURCE_DATA sub = { };
		sub.pSysMem = vertexes.data();

		if (!(GetDevice()->CreateBuffer(&desc, &sub, buffer.GetAddressOf())))
			assert(NULL && "Create vertex buffer Failed!");

		return true;
	}

	void VertexBuffer::Bind()
	{
		UINT vertexSize = sizeof(Vertex);
		UINT offset = 0;
		GetDevice()->BindVertexBuffer(0, 1, buffer.GetAddressOf(), &vertexSize, &offset);
	}
}