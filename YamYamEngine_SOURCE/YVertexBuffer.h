#pragma once
#include "YGraphicDevice_DX11.h"

namespace yam::graphics
{
	class VertexBuffer : public GpuBuffer
	{
	public:
		VertexBuffer();
		~VertexBuffer();

		bool Create(const std::vector<Vertex>& vertexes);
		void Bind();

	private:
	};
}


