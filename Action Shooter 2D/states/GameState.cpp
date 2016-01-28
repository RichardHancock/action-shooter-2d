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
			//temporary movement
			case SDLK_UP:
				kUp = true;
				break;
			case SDLK_DOWN:
				kDown = true;
				break;
			case SDLK_LEFT:
				kLeft = true;
				break;
			case SDLK_RIGHT:
				kRight = true;
				break;
			}
			break;
		case SDL_KEYUP:
			switch (events.key.keysym.sym)
			{
			case SDLK_p:
				particles->generateNewParticles();
				break;

				//temporary movement
			case SDLK_UP:
				kUp = false;
				break;
			case SDLK_DOWN:
				kDown = false;
				break;
			case SDLK_LEFT:
				kLeft = false;
				break;
			case SDLK_RIGHT:
				kRight = false;
				break;
			
			default:
				Utility::log(Utility::I, Utility::intToString(events.key.keysym.sym));
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



	//just some testing data for moving the player
	Vec2 curPos = currentMap->player->getPosition();
	//Utility::log(Utility::I, "X: " + Utility::floatToString(curPos.x) + "Y: " + Utility::floatToString(curPos.y));
	Vec2 movement = Vec2(0);

	if (kLeft)
	{
		movement.x = -1;
	}
	if (kRight)
	{
		movement.x = 1;
	}
	if (kUp)
	{
		movement.y = -1;
	}

	if (kDown)
	{
		movement.y = 1;
	}


	Vec2 normCurPos = movement.normalize();
	int speed = 10;
	curPos += normCurPos * speed * dt * 60;

	//Utility::log(Utility::I, Utility::floatToString(speed * dt * 60));
	//Utility::log(Utility::I, "X: " + Utility::floatToString(normCurPos.x) + " Y: " + Utility::floatToString(normCurPos.y));
	//Utility::log(Utility::I, "X: " + Utility::floatToString(curPos.x) + " Y: " + Utility::floatToString(curPos.y));

	currentMap->player->setPosition(curPos);
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
	//manage tiles
	TileTypeManager* tmp = new TileTypeManager("res/txt/tiles.txt", platform->getRenderer());
	//Creature + character loading test
	CreatureManager* cmtmp = new CreatureManager("res/txt/creatures.txt", "res/txt/characters.txt", platform->getRenderer());
	//load map
	MapManager *mapmng = new MapManager("res/txt/map1.txt", tmp, cmtmp);
	currentMap = mapmng->getMap("M01");

	//grab the player type
	playerType = cmtmp->getCharacterType("P0");
	//shove the type into the map to create a new player
	currentMap->loadPlayer(playerType);



	//Temp Particle Test
	particles = new ParticleSystem(Vec2(320, 240), new Texture(platform->getRenderer(), 255, 255, 255),
		50, Utility::newColour(0,0,0), Utility::newColour(255,255,255));
	particles->setSpeed(15);

	
	
}

void GameState::unload()
{
	delete particles;
}