#include "GameState.h"

GameState::GameState(StateManager* manager, Platform *platform) : State(manager, platform)
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