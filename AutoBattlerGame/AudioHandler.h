#pragma once

#include <Windows.h>
#include <mmsystem.h>
class AudioHandler
{

public:
	AudioHandler();

	void NavigateMenuSoundAudio();

	void ExitNoiseAudio();

	void StopAudio();

	void FictoryFanfareAudio();

	~AudioHandler();
};

