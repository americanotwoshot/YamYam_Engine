#include "YAudioSource.h"
#include "YTransform.h"
#include "YGameObject.h"
#include "YFmod.h"

namespace yam
{
	AudioSource::AudioSource()
		:Component(enums::eComponentType::AudioSource)
	{
	}
	AudioSource::~AudioSource()
	{
	}

	void AudioSource::Initialize()
	{
	}
	void AudioSource::Update()
	{
	}
	void AudioSource::LateUpdate()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		//mAudioClip->Set3DAttributes(pos);
	}
	void AudioSource::Render()
	{
	}

	void AudioSource::Play()
	{
		mAudioClip->Play();
	}
	void AudioSource::Stop()
	{
		mAudioClip->Stop();
	}
	void AudioSource::SetLoop(bool loop)
	{
		mAudioClip->SetLoop(loop);
	}
}