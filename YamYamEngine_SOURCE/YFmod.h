#pragma once
#include "CommonInclude.h"
#include "..\\External\\Include\\fmod_studio.hpp"
#include "..\\External\\Include\\fmod.hpp"
#include "..\\External\\Include\\fmod_common.h"
#include "..\\External\\Include\\fmod_codec.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\External\\Library\\Debug\\fmodL_vc.lib")
#pragma comment(lib, "..\\External\\Library\\Debug\\fmodstudioL_vc.lib")
#else
#pragma comment(lib, "..\\External\\Library\\Release\\fmod_vc.lib")
#pragma comment(lib, "..\\External\\Library\\Release\\fmodstudio_vc.lib")
#endif 

namespace yam
{
	using namespace math;
	class Fmod
	{
	public:
		static void Initialize();
		static bool CreateSound(const std::string& path, FMOD::Sound** sound);
		static void SoundPlay(FMOD::Sound* sound, FMOD::Channel** channel);
		static void Set3DListenerAttributes(const Vector2* pos);
		static void Release();

	private:
		static FMOD::Studio::System* mSystem;
		static FMOD::System* mCoreSystem;
	};
}

