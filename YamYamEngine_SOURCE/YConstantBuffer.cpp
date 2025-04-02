#include "YConstantBuffer.h"

namespace yam::graphics
{
	ConstantBuffer::ConstantBuffer(eCBType type)
		: mSize(0)
		, mType(type)
	{
	}
	ConstantBuffer::~ConstantBuffer()
	{
	}
	bool ConstantBuffer::Create(UINT size, void* data)
	{
		mSize = size;
		desc.ByteWidth = size;
		desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		desc.Usage = D3D11_USAGE_DYNAMIC;
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

		D3D11_SUBRESOURCE_DATA sub = {};
		sub.pSysMem = data;

		bool success = false;
		if (data == NULL)
			success = GetDevice()->CreateBuffer(&desc, nullptr, buffer.GetAddressOf());
		else
			success = GetDevice()->CreateBuffer(&desc, &sub, buffer.GetAddressOf());

		if (!success)
			assert(NULL && "Create constant buffer Failed!");

		return false;
	}

	void ConstantBuffer::SetData(void* data) const
	{
		GetDevice()->SetDataGpuBuffer(buffer.Get(), data, mSize);
	}

	void ConstantBuffer::Bind(eShaderStage stage) const
	{
		GetDevice()->BindConstantBuffer(stage, mType, buffer.Get());
	}
}