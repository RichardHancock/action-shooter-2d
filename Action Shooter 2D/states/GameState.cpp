#include "GameState.h"
#include "../Utility.h"

GameState::GameState(StateManager* manager, Platform *platform)
	: State(manager, platform)
{
	stateName = "GameState";
}

GameState::~GameState()
{

}

bool GameState::eventHandler()
{
	//temporary input handling
	SDL_Event events;
	while (SDL_PollEvent(&events))
	{
		switch (events.type)
		{
		case SDL_QUIT:
			return true;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (events.button.button)
			{
			case SDL_BUTTON_LEFT:
				Utility::log(Utility::I, "Clicking");
			}
			break;
		case SDL_KEYDOWN:
			switch (events.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				//do same as quit
				return true;
				break;
			}
			break;
		case SDL_KEYUP:
			switch (events.key.keysym.sym)
			{
			case SDLK_p:
				particles->generateNewParticles();
				break;
			}
			break;
		}
	}
	return false;
}

void GameState::update(float dt)
{
	particles->update(dt);
}

void GameState::render()
{
	//TMP FOR TESTING
	currentMap->render(platform->getRenderer());

	particles->render(platform);
}

void GameState::load()
{
	//TMP FOR TESTING
	TileTypeManager* tmp = new TileTypeManager("res/txt/tiles.txt", platform->getRenderer());
	MapManager *mapmng = new MapManager("res/txt/map1.txt", tmp);
	currentMap = mapmng->getMap("M01");

	//Temp Particle Test
	particles = new ParticleSystem(Vec2(320, 240), new Texture(platform->getRenderer(), 255, 255, 255),
		50, Utility::newColour(0,0,0), Utility::newColour(255,255,255));
	particles->setSpeed(15);
}

void GameState::unload()
{
	delete particles;
}