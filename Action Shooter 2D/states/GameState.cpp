#include "GameState.h"
#include "../levelManagement/Map.h"

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
	return 1;
}

void GameState::update(float dt)
{

}

void GameState::render()
{

}

void GameState::load()
{
	Map *m = new Map(Vec2(0, 0), Vec2(10, 10));

	//TMP FOR TESTING
	TileTypeManager* tmp = new TileTypeManager("res/txt/tiles.txt", platform->getRenderer());
}

void GameState::unload()
{
	
}