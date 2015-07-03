#include "Utility.h"
#include <sstream>

void Utility::randomInit()
{
	srand((unsigned int) time(NULL));
}

int Utility::randomInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

float Utility::randomFloat(float min, float max)
{
	// Not written by me it's from: http://stackoverflow.com/a/5289624
	// Could have used C++11 for random floats, but I think this is adequate.
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = max - min;
	float r = random * diff;
	return min + r;
}

void Utility::log(LogType type, std::string message)
{
	//Get current time
	time_t currentTime = time(NULL);
	
	char textTime[9];

	#ifdef _MSC_VER
		//Because Microsoft like to be different they depreceated the normal localtime(), and most compilers implement localtime_r() not _s
		tm timeStruct;
		localtime_s(&timeStruct, &currentTime);

		strftime(textTime,9, "%H:%M:%S", &timeStruct);

	#else

		tm* timeStruct;
		timeStruct = localtime(&currentTime);
		
		strftime(textTime, 11, "%T", timeStruct); //Apparently only Microsoft don't support the %T.

	#endif
	
	std::string finalMsg = textTime;

	switch (type)
	{
	case I:
		finalMsg += (" " + message);
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, finalMsg.c_str());
		break;

	case W:
		finalMsg += (" " + message);
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, finalMsg.c_str());
		break;

	case E:
		finalMsg += (" " + message);
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, finalMsg.c_str());
		break;

	default:
		finalMsg += (" Uncategorized: " + message);
		SDL_Log(finalMsg.c_str());
		break;

	}
}

void Utility::logI(std::string message)
{
	Utility::log(Utility::I, message);
}

void Utility::logW(std::string message)
{
	Utility::log(Utility::W, message);
}

void Utility::logE(std::string message)
{
	Utility::log(Utility::E, message);
}

std::string Utility::intToString(int num)
{
	std::stringstream stream;

	stream << num;
	std::string result = stream.str();

	return result;
	
}

std::string Utility::floatToString(float num)
{
	std::stringstream stream;

	stream << num;
	std::string result = stream.str();

	return result;

}

std::string Utility::vec2ToString(Vec2 num)
{
	std::stringstream stream;

	stream << num.x;
	stream << ", ";
	stream << num.y;
	std::string result = stream.str();

	return result;

}

Vec2 Utility::scaleTo(Vec2 vecToScale, Vec2 screenSize)
{
	vecToScale.x /= 640;
	vecToScale.y /= 480;

	return (vecToScale * screenSize);
}

int Utility::fontSizeScale(int intToScale, Vec2 screenSize)
{
	int percentageChange = (int)(screenSize.x / 640.0f);

	return (intToScale * percentageChange);
}

Vec2 Utility::getRectCenter(SDL_Rect rect)
{
	Vec2 center;
	center.x = (float)(rect.x + (rect.w / 2));
	center.y = (float)(rect.y + (rect.h / 2));
	return center;
}

bool Utility::lineIntersection(Vec2 a1, Vec2 a2, Vec2 b1, Vec2 b2)
{
	Vec2 b = a2 - a1;
	Vec2 d = b2 - b1;
	float bDotDPerp = b.x * d.y - b.y * d.x;

	// if b dot d == 0, it means the lines are parallel so have infinite intersection points
	if (bDotDPerp == 0)
		return false;

	Vec2 c = b1 - a1;
	float t = (c.x * d.y - c.y * d.x) / bDotDPerp;
	if (t < 0 || t > 1)
		return false;

	float u = (c.x * b.y - c.y * b.x) / bDotDPerp;
	if (u < 0 || u > 1)
		return false;

	return true;
}

bool Utility::lineIntersection(Vec2 a1, Vec2 a2, Vec2 b1, Vec2 b2, Vec2& intersectPoint)
{
	intersectPoint = 0;

	Vec2 b = a2 - a1;
	Vec2 d = b2 - b1;
	float bDotDPerp = b.x * d.y - b.y * d.x;

	// if b dot d == 0, it means the lines are parallel so have infinite intersection points
	if (bDotDPerp == 0)
		return false;

	Vec2 c = b1 - a1;
	float t = (c.x * d.y - c.y * d.x) / bDotDPerp;
	if (t < 0 || t > 1)
		return false;

	float u = (c.x * b.y - c.y * b.x) / bDotDPerp;
	if (u < 0 || u > 1)
		return false;

	intersectPoint = a1 + b * t;

	return true;
}

bool Utility::lineRectIntersection(Vec2 lineP1, Vec2 lineP2, SDL_Rect rect)
{
	//Could have used this instead: https://wiki.libsdl.org/SDL_IntersectRectAndLine

	//tl - top left/ tr - top right/ bl - bottom left/ br - bottom right
	Vec2 tl((float)rect.x, (float)rect.y);
	Vec2 tr = tl;
	tr.x += rect.w;

	Vec2 bl = tl;
	bl.y += rect.h;
	Vec2 br = tr;
	br.y += rect.h;
	
	if (
		lineIntersection(lineP1, lineP2, tl, tr) ||
		lineIntersection(lineP1, lineP2, tr, br) ||
		lineIntersection(lineP1, lineP2, br, bl) ||
		lineIntersection(lineP1, lineP2, bl, tl)
	)
	{
		return true;
	}
	else
	{
		return false;
	}
}

SDL_Colour Utility::newColour(int r, int g, int b)
{
	SDL_Colour colour;
	colour.r = r;
	colour.g = g;
	colour.b = b;
	return colour;
}

//Timer

std::unordered_map<std::string, Utility::Timer::TimerStruct> Utility::Timer::timers;
const float Utility::Timer::TIME_INTERVAL = 1.0f;

Utility::Timer::Timer() {}

void Utility::Timer::update(float dt)
{
	//Need auto& to get a reference otherwise it's just a local copy (Really Fun Bug to Find)
	for (auto& timer : timers)
	{
		timer.second.currentTime += (float)(TIME_INTERVAL * dt);
	}
}

bool Utility::Timer::createTimer(std::string id, float duration)
{
	//Unordered map can't have duplicates
	if (timers.count(id) == 1)
	{
		log(W,"Timer id specified already exists");
		return false;
	}

	//Create the Timer
	TimerStruct timer = {0.0f, duration};

	//Push it into the timers unordered_map
	timers.insert(std::make_pair(id,timer));

	return true;
}

float Utility::Timer::stopTimer(std::string id)
{
	if (timers.count(id) == 0) { return -1.0f; }

	float finalCurrentTime = timers[id].currentTime;

	timers.erase(id);

	return finalCurrentTime;
}

bool Utility::Timer::hasTimerFinished(std::string id)
{
	if (!timers.count(id))
	{
		log(W,"Unknown timer was asked if finished. Timer ID:" +id);
		return false;
	}
	
	TimerStruct timer = timers[id];
	if (timer.currentTime >= timer.duration)
	{
		//Could call stop timer but would have an extra id check (Which is wasteful)
		timers.erase(id);
		return true;
	}
	else
	{
		return false;
	}
}

void Utility::Timer::cleanup()
{
	timers.clear();
}