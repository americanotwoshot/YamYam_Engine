#pragma once
#include "YGraphicDevice_DX11.h"

namespace yam::graphics
{
	class IndexBuffer : public GpuBuffer
	{
	public:
		IndexBuffer();
		~IndexBuffer();

		bool Create(const std::vector<UINT>& indices);
		void Bind() const;

	private:
	};
}


