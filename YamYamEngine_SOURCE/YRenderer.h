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

	void Initialize();
	void Release();
}

