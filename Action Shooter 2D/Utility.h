#pragma once

#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <string>
#include "dependencies/SDL.h"
#include <unordered_map>

#include "Vec2.h"

//Namespace has been used in other assignments, but some functions have been modified to
//be portable between platforms (Such as the log function).

/**
@brief An assortment of useful functions (random numbers, logging) that don't fit elsewhere.
*/
namespace Utility
{

	/**
	@brief Initialize the Random Number functions

	Call this before any random functions, else random will be the same
	sequence of numbers for each program execution.
	*/
	void randomInit();

	/**
	@brief Generate a random integer number between min and max

	@param int - Minimum Number for the range
	@param int - Maximum Number for the range
	@return int - Random int between min and max
	*/
	int randomInt(int min, int max);

	/**
	@brief Generate a random float number between min and max

	@param float - Minimum Number for the range
	@param float - Maximum Number for the range
	@return float - Random float between min and max
	*/
	float randomFloat(float min, float max);

	/**
	@brief A type of log message
	*/
	enum LogType
	{
		E, //< Error
		W, //< Warning
		I  //< Info
	};

	/**
	@brief Log a message to the console

	Made this one function instead of multiple to reduce clutter. Uses SDL_Log internally to
	make it function on multiple platforms easily.
	@param LogType - Type of message E: Error, W: Warning, I: Info
	@param std::string - The message to log
	*/
	void log(LogType, std::string);

	/**
	 @brief Converts int to a string 
	 Created because some compilers still don't support std::to_string()
	
	 @param num - Number to convert.
	
	 @return std::string - Converted string.
	 */
	std::string intToString(int num);

	/**
	 @brief Converts float to a string 
	 Created because some compilers still don't support std::to_string()
	
	 @param num - Number to convert.
	
	 @return std::string - Converted string.
	 */
	std::string floatToString(float num);

	/**
	 @brief Converts a Vector 2 to a string.
	
	 @param num Vector2 to convert.
	
	 @return A std::string formatted like this "Vec2(x, y)".
	 */
	std::string vec2ToString(Vec2 num);

	/**
	 @brief Scale a Vec2 relative to the passed in screen size (Bases everything on a base resolution of 640,480).
	
	 @param vecToScale The vector to scale.
	 @param screenSize Size of the screen.
	
	 @return A scaled Vec2.
	 */
	Vec2 scaleTo(Vec2 vecToScale, Vec2 screenSize);

	/**
	 @brief Scales the font size by screen size to make text appear less blurry.
	
	 @param intToScale The int to scale.
	 @param screenSize Size of the screen.
	
	 @return Scaled int.
	 */
	int fontSizeScale(int intToScale, Vec2 screenSize);

	/**
	@brief Returns the center position of a rectangle
	@param SDL_Rect - Rectangle struct
	@return Vec2 - Center position of the rectangle
	*/
	Vec2 getRectCenter(SDL_Rect rect);

	/**
	@brief Checks if two lines intersect
	Code originally from: http://stackoverflow.com/a/3746601
	@param Vec2 - Line A point 1
	@param Vec2 - Line A point 2
	@param Vec2 - Line B point 1
	@param Vec2 - Line B point 2
	@return bool - Is there an intersection
	*/
	bool lineIntersection(Vec2 a1, Vec2 a2, Vec2 b1, Vec2 b2);

	/**
	@brief Checks if two lines intersect
	Code originally from: http://stackoverflow.com/a/3746601
	@param Vec2 - Line A point 1
	@param Vec2 - Line A point 2
	@param Vec2 - Line B point 1
	@param Vec2 - Line B point 2
	@param Vec2& - out, The point where intersection occured
	@return bool - Is there an intersection
	*/
	bool lineIntersection(Vec2 a1, Vec2 a2, Vec2 b1, Vec2 b2, Vec2& intersectPoint);

	/**
	@brief Checks for Intersection between a line and a rect
	@param Vec2 - Line Point 1
	@param Vec2 - Line Point 2
	@param SDL_Rect - A rectangle
	@return bool - Is there an intersection
	*/
	bool lineRectIntersection(Vec2 lineP1, Vec2 lineP2, SDL_Rect rect);

	/**
	@brief Enum containing all types of tiles
	
	This was in the level manager but was causing a recursive include loop that is easily avoided putting it here.
	*/
	enum TileType
	{
		blank = 0,
		floor,
		wall,
	};

	//Timer Management

	/**
	@brief creates a timer for use in game

	This code was used in the Group Project Unit, but was entirely written by me.
	I have upgraded it to use some really useful C++11 which did require a rewrite of all the functions, 
	but the general structure (Headers) is the same.
	*/
	class Timer
	{
	private:
		///a structure for the individual timers
		struct TimerStruct
		{
			float currentTime;
			float duration;
		};
	public:
		/**
		updates the time in the timer

		@param float - delta time
		*/
		static void update(float dt);

		/**
		Creates a new timer with a unique id and a duration

		@param std::string - The id of the timer
		@param float - the duration of the timer
		@returns bool - false if id is not unique
		*/
		static bool createTimer(std::string id, float duration);

		/**
		Stops the time and returns the time taken

		@param std::string - The id of the timer
		@returns float - the time taken
		*/
		static float stopTimer(std::string id);

		/**
		Checks to see if the timer has finished

		@param std::string - The id of the timer
		@returns bool - if the timer has ended
		*/
		static bool hasTimerFinished(std::string id);

		/**
		@brief Deletes all timers
		*/
		static void cleanup();

	private:
		//No one should call this so it is private
		Timer();

		static const float TIME_INTERVAL;

		/**
		@brief Stores the Timers

		1 - currentTime
		2 - duration
		*/
		static std::unordered_map<std::string, TimerStruct> timers;
	};
}

/**
@brief Defines a RGB colour

Didn't realise there was a SDL_Colour until it was too late, oh well...
*/
struct Colour
{
	uint8_t r; //< Red Channel
	uint8_t g; //< Green Channel
	uint8_t b; //< Blue Channel

	/**
	@brief Colour
	@param uint8_t - Red
	@param uint8_t - Green
	@param uint8_t - Blue
	*/
	Colour(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}
};
