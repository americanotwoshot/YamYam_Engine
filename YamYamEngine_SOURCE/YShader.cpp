#include "YShader.h"

namespace yam::graphics
{
	Shader::Shader()
		: Resource(enums::eResourceType::Shader)
	{
	}

	Shader::~Shader()
	{
	}

	HRESULT Shader::Load(const std::wstring& path)
	{
		int fileNameBeginOffset = path.rfind(L"\\") + 1;
		int fileNameLength = path.length() - fileNameBeginOffset;
		const std::wstring fileName(path.substr(
			fileNameBeginOffset, fileNameLength));

		if (!Create(eShaderStage::VS, fileName))
			return S_FALSE;
		if (!Create(eShaderStage::PS, fileName))
			return S_FALSE;

		return S_OK;
	}

	bool Shader::Create(const eShaderStage stage, const std::wstring& fileName)
	{
		if (stage == eShaderStage::VS)
			CreateVertexShader(fileName);
		if (stage == eShaderStage::PS)
			CreatePixelShader(fileName);

		return true;
	}

	bool Shader::CreateVertexShader(const std::wstring& fileName)
	{
		if (!(GetDevice()->CreateVertexShader(fileName
			, mVSBlob.GetAddressOf(), mVS.GetAddressOf())))
			return false;

		return true;
	}

	bool Shader::CreatePixelShader(const std::wstring& fileName)
	{
		if (!(GetDevice()->CreatePixelShader(fileName
			, mPSBlob.GetAddressOf(), mPS.GetAddressOf())))
			return false;

		return true;
	}

	void Shader::Bind()
	{
		if (mVS)
			GetDevice()->BindVS(mVS.Get());
		if (mPS)
			GetDevice()->BindPS(mPS.Get());
	}
}