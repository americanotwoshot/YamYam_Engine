#pragma once
#include "YCamera.h"
#include "YGraphicDevice_DX11.h"

#include "YConstantBuffer.h"

using namespace yam::math;
using namespace yam::graphics;

namespace yam::renderer
{
	extern Camera* mainCamera;
	
	extern ConstantBuffer constantBuffer[(UINT)eCBType::End];

	extern 	Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerStates[(UINT)eSamplerType::End];
	extern 	Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[(UINT)eRasterizerState::End];
	extern 	Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[(UINT)eBlendState::End];
	extern 	Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[(UINT)eDepthStencilState::End];

	void Initialize();
	void Release();
}

