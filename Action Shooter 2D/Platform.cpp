#include "Platform.h"
#include "Utility.h"
#include <string>

Platform::Platform()
	: scale(Vec2(640, 480))
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

bool Platform::initSDL()
{
	bool status = true;
	
	#ifndef __ANDROID__
		//Android doesn't need this at SDL internally does this
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) 
		{ 
			status = false; 
			Utility::log(Utility::E, "SDL Init failed: " + std::string(SDL_GetError()));
		}
	#endif
	
	//SDL TTF Initialization
	if (TTF_Init() < 0)
	{
		status = false;
		Utility::log(Utility::E, "SDL_ttf init failed: " + std::string(TTF_GetError()));
	}

	//SDL Mixer Initialization
	Mix_Init(MIX_INIT_OGG);
	//Initialize SDL_Mixer with some standard audio formats/freqs. Also set channels to 2 for stereo sound.
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		status = false;
		Utility::log(Utility::E, "SDL_mixer init failed: " + std::string(Mix_GetError()));
	}
	
	//SDL Image Initialization
	int flags= IMG_INIT_PNG;
	int result = IMG_Init(flags);
	
	// If the inputed flags are not returned, an error has occurred
	if((result & flags) != flags) 
	{
		Utility::log(Utility::E, "Failed to Initialise SDL_Image and png support: "+ std::string(IMG_GetError()));
	}

	#ifdef __ANDROID__
	
		//SDL Android is very temperamental here, but these settings work fine
		if(SDL_CreateWindowAndRenderer(0, 0, 0, &window, &renderer) < 0)
		{
			status = false;
			Utility::log(Utility::E, "Android Window/Renderer failed to be created: " + 
				std::string(SDL_GetError()));
		}

		if (window == NULL || renderer == NULL) 
		{ 
			status = false;
			Utility::log(Utility::E, "Window/Renderer failed to be created: " + 
				std::string(SDL_GetError()));
		}
	
	#else
	
		window = SDL_CreateWindow("2D Action Shooter",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		640, 480,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (!window || !renderer) 
		{ 
			status = false;
			Utility::log(Utility::E, "Window/Renderer failed to be created: " + 
				std::string(SDL_GetError()));
		}
	
	#endif

	int width;
	int height;

	SDL_GetWindowSize(window, &width, &height);

	windowSize.x = (float)width;
	windowSize.y = (float)height;
	
	Utility::log(Utility::I, "Window Dimensions: " + Utility::intToString(width) +
		"x" + Utility::intToString(height));

	return status;
}

