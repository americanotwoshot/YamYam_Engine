#include "YAudioListener.h"
#include "YTransform.h"
#include "YGameObject.h"
#include "YFmod.h"

namespace yam
{
	AudioListener::AudioListener()
		:Component(enums::eComponentType::AudioListener)
	{
	}
	AudioListener::~AudioListener()
	{
	}

	void AudioListener::Initialize()
	{
	}
	void AudioListener::Update()
	{
	}
	void AudioListener::LateUpdate()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Fmod::Set3DListenerAttributes(&pos);
	}
	void AudioListener::Render(HDC hdc)
	{
	}
}