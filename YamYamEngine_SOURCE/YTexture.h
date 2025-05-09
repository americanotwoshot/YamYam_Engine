#pragma once
#include <DirectXTex.h>
#include <DirectXTex.inl>
#include <DirectXTexEXR.h>

#include "YResource.h"
#include "YGraphicDevice_DX11.h"

namespace yam::graphics
{
	class Texture : public Resource
	{
	public:
		Texture();
		~Texture();

		virtual HRESULT Save(const std::wstring& path) override;
		virtual HRESULT Load(const std::wstring& path) override;

		bool Create(UINT width, UINT height, DXGI_FORMAT format, UINT bindFlag);
		bool CreateSRV();
		bool CreateUAV();
		bool CreateRTV();
		bool CreateDSV();
		bool CreateGpuView(UINT flag);

		void Bind(eShaderStage stage, UINT startSlot);

		Microsoft::WRL::ComPtr<ID3D11Texture2D> GetTexture() { return mTexture; }
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>  GetSRV() { return mSRV; }
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView>	  GetRTV() { return mRTV; }
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView>	  GetDSV() { return mDSV; }
		Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> GetUAV() { return mUAV; }
		void SetSRV(Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> srv) { mSRV = srv; }
		void SetRTV(Microsoft::WRL::ComPtr<ID3D11RenderTargetView> rtv) { mRTV = rtv; }
		void SetDSV(Microsoft::WRL::ComPtr<ID3D11DepthStencilView> dsv) { mDSV = dsv; }
		void SetUAV(Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> uav) { mUAV = uav; }

	private:
		ScratchImage mImage;

		D3D11_TEXTURE2D_DESC mDesc;
		Microsoft::WRL::ComPtr<ID3D11Texture2D> mTexture;

		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>  mSRV;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView>	  mRTV;
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView>    mDSV;
		Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> mUAV;
	};
}

