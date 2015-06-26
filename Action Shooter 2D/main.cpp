#include "dependencies/SDL.h"

#include "Platform.h"
#include "Utility.h"
#include "states/StateManager.h"

#include "states/GameState.h"

int main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	Platform* platform = new Platform("2D Action Shooter");
	
	if (!platform->initSDL())
	{
		Utility::log(Utility::E, "SDL Failed to initialize");
		exit(1);
		return 1;
	}

	Utility::randomInit();

	SDL_Renderer* renderer = platform->getRenderer();
	SDL_Window* window = platform->getWindow();

	StateManager* manager = new StateManager();

	unsigned int lastTime = SDL_GetTicks();


	manager->addState(new GameState(manager, platform));

	bool done = false;

	while (!done)
	{
		done = manager->eventHandler();

		// Update
		//Calculate deltaTime
		unsigned int current = SDL_GetTicks();
		float dt = (float)(current - lastTime) / 1000.0f;
		lastTime = current;

		manager->update(dt);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		manager->render();

		SDL_RenderPresent(renderer);

		if (dt < (1.0f / 50.0f))
		{
			SDL_Delay((unsigned int)(((1.0f / 50.0f) - dt)*1000.0f));
		}
	}

	delete manager;
	delete platform;
	SDL_Quit();
	exit(0);
	return 0;
}