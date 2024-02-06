#include "AudioHandler.h"

AudioHandler::AudioHandler()
{

}

void AudioHandler::NavigateMenuSoundAudio()
{
	PlaySound(TEXT("NavigateMenuSound.wav"), NULL, SND_ASYNC);
}

void AudioHandler::ExitNoiseAudio()
{
	PlaySound(TEXT("ExitNoise.wav"), NULL, SND_ASYNC);
}

void AudioHandler::StopAudio()
{
	PlaySound(NULL, NULL, 0);
}

void AudioHandler::FictoryFanfareAudio()
{
	PlaySound(TEXT("Victory_Fanfare.wav"), NULL, SND_ASYNC);
}

AudioHandler::~AudioHandler()
{

}
