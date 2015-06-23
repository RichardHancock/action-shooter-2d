#include "SFX.h"

#include "Music.h"
#include "../Utility.h"

SFX::SFX(std::string path)
	: Audio(path), channel(0)
{
	load();
}

SFX::~SFX()
{
	Mix_FreeChunk(sound);
}

void SFX::play(unsigned int ms, int loops)
{
	int newChannel;
	newChannel = (ms <= 0 ? Mix_PlayChannel(-1, sound, loops)
		: Mix_FadeInChannel(-1, sound, loops, ms));

	if (newChannel == -1)
	{
		Utility::log(Utility::W, "Problem trying to play sound: " + path + " Error msg: " + Mix_GetError());
	}
	else
	{
		channel = newChannel;
	}
}

void SFX::togglePause()
{
	// If Music paused resume, else pause 
	Mix_Paused(channel) ? Mix_Resume(channel) : Mix_Pause(channel);
}

void SFX::stop(int ms)
{
	//If no ms value has been given stop sound, else fade out sound.
	ms <= 0 ? Mix_HaltChannel(channel) : Mix_FadeOutChannel(channel, ms);
}

void SFX::load()
{
	sound = Mix_LoadWAV(path.c_str());
	if (sound == nullptr)
	{
		Utility::log(Utility::W, "Sound file: " + path + " failed to load. " + Mix_GetError());
	}
}