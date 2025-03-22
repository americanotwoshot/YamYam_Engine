#pragma once
#include "YGraphicDevice_DX11.h"

namespace yam::graphics
{
	class ConstantBuffer : public GpuBuffer 
	{
	public:
		ConstantBuffer();
		~ConstantBuffer();

		bool Create(eCBType type, UINT size, void* data = NULL);

		void SetData(void* data);
		void Bind(eShaderStage stage);

	private:
		UINT mSize;
		eCBType mType;
	};
}

