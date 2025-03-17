#pragma once
#include "YFmod.h"
#include "YResource.h"

namespace yam
{
	class AudioClip : public Resource
	{
	public:
		AudioClip();
		virtual ~AudioClip();

		virtual HRESULT Load(const std::wstring& path) override;

	private:
		FMOD::Sound* mSound;
		FMOD::Channel* mChannel;
	};
}

