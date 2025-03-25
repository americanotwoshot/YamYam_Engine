#include "YTexture.h"
#include "YApplication.h"
#include "YResources.h"

extern yam::Application application;

namespace yam::graphics
{
	Texture::Texture()
		: Resource(enums::eResourceType::Texture)
		, mDesc{}
	{

	}
	Texture::~Texture()
	{

	}

	HRESULT Texture::Save(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	HRESULT Texture::Load(const std::wstring& path)
	{
		std::wstring ext
			= path.substr(path.find_last_of(L".") + 1);

		if (ext == L".dds" || ext == L".DDS")
		{
			if (FAILED(LoadFromDDSFile(path.c_str()
				, DDS_FLAGS::DDS_FLAGS_NONE, nullptr, mImage)))
				return S_FALSE;
		}
		else if (ext == L".tga" || ext == L".TGA")
		{
			if (FAILED(LoadFromTGAFile(path.c_str(), nullptr, mImage)))
				return S_FALSE;
		}
		else // WIC (png, jpg, jpeg, bmp)
		{
			HRESULT hr = LoadFromWICFile(path.c_str()
				, WIC_FLAGS::WIC_FLAGS_NONE, nullptr, mImage);
			if (FAILED(hr)) {
				std::wcerr << L"Failed to load image! HRESULT: " << std::hex << hr << std::endl;
				return S_FALSE;
			}
		}

		HRESULT hr = CreateShaderResourceView(graphics::GetDevice()->GetID3D11Device().Get()
			, mImage.GetImages()
			, mImage.GetImageCount()
			, mImage.GetMetadata()
			, mSRV.GetAddressOf());

		if (hr == S_FALSE)
			assert(NULL && "Load Texture Failed!");

		mSRV->GetResource((ID3D11Resource**)mTexture.GetAddressOf());

		return S_OK;
	}

	void Texture::Bind(eShaderStage stage, UINT startSlot)
	{
		graphics::GetDevice()->SetShaderResource(stage, startSlot
			, mSRV.GetAddressOf());
	}

}
