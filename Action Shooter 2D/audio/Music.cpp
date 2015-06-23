#include "Music.h"
#include "../Utility.h"

Music::Music(std::string path)
	: Audio(path)
{
	load();
}

Music::~Music()
{
	Mix_FreeMusic(music);
}

void Music::play(unsigned int ms, int loops)
{
	int success;
	if (!ms)
	{
		success = Mix_PlayMusic(music, loops);
	}
	else 
	{
		success = Mix_FadeInMusic(music, loops, ms);
	}

	if (success < 0) 
	{ 
		Utility::log(Utility::W, "Problem trying to play music: " + path + " Error msg: " + Mix_GetError()); 
	}
}

void Music::togglePause()
{
	// If Music paused resume, else pause 
	if (Mix_PlayingMusic())
	{
		Mix_PausedMusic() ? Mix_ResumeMusic() : Mix_PauseMusic();
	}
	else
	{
		play(0, 0);
	}
	
}

void Music::stop(int ms)
{
	//If no ms value has been given stop music, else fade out music.
	ms <= 0 ? Mix_HaltMusic() : Mix_FadeOutMusic(ms);
}

void Music::load()
{
	music = Mix_LoadMUS(path.c_str());
	if (music == nullptr)
	{
		Utility::log(Utility::W, "Music file: " + path + " failed to load. " + Mix_GetError());
	}
}