#pragma once

#include "Audio.h"

//Self Reference: This code was used in a previous assignment

/**
@class SFX
@brief Encapsulates a Sound Effect
*/
class SFX : public Audio
{
public:
	/**
	@brief Create an Sound Effect object
	@param std::string - Path to the sound file
	*/
	SFX(std::string);
	~SFX();

	/**
	@brief Play the stored Sound Effect

	@param unsigned int - milliseconds of fade-in
	@param int - How many times will this SFX play (-1 for infinite , 0 to just play once)
	*/
	void play(unsigned int, int);

	/**
	@brief Pause/Resume the Sound Effect
	*/
	void togglePause();

	/**
	@brief Stop the stored Sound Effect
	@param int - milliseconds of fade-out
	*/
	void stop(int);
private:
	/**
	@brief Loads a Sound Effect file and stores it internally
	*/
	void load();

	///Currently assigned channel for the sound effect
	int channel;

	///Sound data
	Mix_Chunk* sound;
};