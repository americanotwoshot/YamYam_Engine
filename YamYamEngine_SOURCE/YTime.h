#pragma once
#include "CommonInclude.h"

namespace yam
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render();
		
		static float DeltaTime() { return DeltaTimeValue; }

	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTimeValue;
	};
}

