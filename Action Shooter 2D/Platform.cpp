#include "Platform.h"
#include "Utility.h"
#include <string>

Platform::Platform(std::string windowTitle)
	: windowTitle(windowTitle)
{
	
}

Platform::~Platform()
{
	IMG_Quit();
	Mix_CloseAudio();
	Mix_Quit();
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

bool Platform::initSDL(int imageInitFlags, int mixerInitFlags)
{
#ifndef __ANDROID__
	//Android doesn't need this as SDL internally does this
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) 
	{ 
		Utility::log(Utility::E, "SDL Init failed: " + std::string(SDL_GetError()));
		return false;
	}
#endif
	
	//Initialise SDL's addons
	if (!ttfInit() || !imageInit(imageInitFlags) || !mixerInit(mixerInitFlags))
	{
		return false;
	}

#ifdef __ANDROID__
	
	//Initialise Android
	if (!androidInit()) { return false; }
	
#else
	
	window = SDL_CreateWindow(windowTitle.c_str(),
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	640, 480,
	SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	renderer = SDL_CreateRenderer(window, -1, 0);

	if (!window || !renderer) 
	{ 
		Utility::logE("Window/Renderer failed to be created: " + 
			std::string(SDL_GetError()));
		return false;
	}
	
#endif
	
	//Get Window's dimensions
	int width;
	int height;

	SDL_GetWindowSize(window, &width, &height);

	windowSize = Vec2(width, height);
	
	Utility::log(Utility::I, "Window Dimensions: " + Utility::intToString(width) +
		"x" + Utility::intToString(height));

	return true;
}

bool Platform::androidInit()
{
#ifdef __ANDROID__

	//SDL Android is very temperamental here, but these settings work fine
	if (SDL_CreateWindowAndRenderer(0, 0, 0, &window, &renderer) < 0)
	{
		Utility::log(Utility::E, "Android Window/Renderer failed to be created: " +
			std::string(SDL_GetError()));
		return false;
	}

	if (window == NULL || renderer == NULL)
	{
		Utility::log(Utility::E, "Window/Renderer failed to be created: " +
			std::string(SDL_GetError()));
		return false;
	}

	return true;

#else

	Utility::logE("androidInit was called on a non android platform");
	return false;

#endif
}

bool Platform::imageInit(int initFlags)
{
	int flags = IMG_Init(initFlags);

	//Check if all formats were loaded
	if ((flags & initFlags) != initFlags)
	{
		Utility::log(Utility::E, "SDL_image failed to Initialise itself or some requested formats: " 
			+ std::string(IMG_GetError()));
		return false;
	}

	return true;
}

bool Platform::mixerInit(int initFlags)
{
	int flags = Mix_Init(initFlags);

	//Check if all formats were loaded
	if ((flags&initFlags) != initFlags)
	{
		Utility::logE("SDL_mixer failed to initialise itself or some requested formats: "
			+ std::string(Mix_GetError()));
		return false;
	}

	//Open audio with some standard audio formats/freqs. Also set channels to 2 for stereo sound.
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		Utility::logE("SDL_mixer open audio failed: " + std::string(Mix_GetError()));
		return false;
	}

	return true;
}

bool Platform::ttfInit()
{
	if (TTF_Init() == -1)
	{
		Utility::logE("SDL_ttf init failed: " + std::string(TTF_GetError()));
		return false;
	}
	
	return true;
}