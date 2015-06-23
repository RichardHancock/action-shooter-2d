#pragma once

#include "../dependencies/SDL_mixer.h"
#include <string>

//Self Reference: This code was used in a previous assignment

/**
@class Audio
@brief Abstract base class for any Audio
*/
class Audio
{
public:

	/**
	@brief Create an Audio object.
	
	@param path Path to the audio file.
	 */
	Audio(std::string path);

	/**
	@brief Play the stored Audio.
	
	@param ms    milliseconds of fade-in.
	@param loops How many times will this audio play (-1 for infinite , 0 to just play once)
	 */
	virtual void play(unsigned int ms, int loops) = 0;

	/**
	@brief Pause/Resume the audio
	*/
	virtual void togglePause() = 0;

	/**
	@brief Stop the stored Audio.
	
	@param ms milliseconds of fade-out.
	 */
	virtual void stop(int ms) = 0;
protected:
	/**
	@brief Loads a audio file and stores it internally
	*/
	virtual void load() = 0;

	///Path to the stored audio file
	std::string path;
};