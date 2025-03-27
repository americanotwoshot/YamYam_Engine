#pragma once
#include "YGraphicDevice_DX11.h"

namespace yam::graphics
{
	class InputLayout
	{
	public:
		InputLayout();
		~InputLayout();

		bool CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* layout, UINT vertexCount
			, const void* pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength);
		void Bind();

	private:
		Microsoft::WRL::ComPtr<ID3D11InputLayout> mInputLayout;
	};
}


