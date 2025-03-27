#include "YInputLayout.h"

namespace yam::graphics
{
	InputLayout::InputLayout()
		:mInputLayout(nullptr)
	{
	}
	InputLayout::~InputLayout()
	{
	}
	bool InputLayout::CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* layout, UINT vertexCount
		, const void* pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength)
	{
		if (!(GetDevice()->CreateInputLayout(layout, vertexCount
			, pShaderBytecodeWithInputSignature
			, BytecodeLength
			, mInputLayout.GetAddressOf())))
			assert(NULL && "Create input layout Failed!");
		
		return true;
	}
	void InputLayout::Bind()
	{
		if (mInputLayout)
			GetDevice()->BindInputLayout(mInputLayout.Get());
	}
}