#pragma once

#include "Audio.h"

//Self Reference: This code was used in a previous assignment

/**
@class Music
@brief Encapsulates music

Only one Music class can play at a time, there is no check for this so the outcome is unhandled.
*/
class Music : public Audio
{
public:
	/**
	@brief Create an Music object
	@param std::string - Path to the music file
	*/
	Music(std::string);

	~Music();

	/**
	@brief Play the stored music
	
	@param unsigned int - milliseconds of fade-in
	@param int - How many times will this music play (-1 for infinite)
	*/
	void play(unsigned int, int);

	/**
	@brief Pause/Resume the current music track
	*/
	void togglePause();

	/**
	@brief Stop the stored music

	@param int - milliseconds of fade-out
	*/
	void stop(int);
private:
	/**
	@brief Loads a music file and stores it internally
	*/
	void load();

	///Music data
	Mix_Music* music;
};