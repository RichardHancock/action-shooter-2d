#include "GameState.h"
#include "Map.h"

GameState::GameState(StateManager* manager, Platform *platform) : State(manager, platform)
{
	stateName = "GameState";

	Map *m = new Map(Vec2(0, 0), Vec2(10, 10));
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