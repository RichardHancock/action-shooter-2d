#pragma once

#include "states/State.h"
#include "Platform.h"

/**
@class State
@brief A game state that contains one screen of the game such as a Menu or the game itself
*/
class GameState : public State
{
public:

	/**
	@brief Create the GameState.

	@param [in,out] manager  - Pointer to the current state manager.
	@param [in,out] platform - Platform containing OS dependent data.
	*/

	GameState(StateManager* manager, Platform *platform);
	~GameState();

	/**
	@brief Handles any events such as keyboard/mouse input.

	@return true to exit, false to continue.
	*/
	bool eventHandler();

	/**
	@brief Update any internal values.

	@param dt - delta time.
	*/
	void update(float dt);

	/**
	@brief Render any sprites relevant to the state
	*/
	void render();

protected:
	///Pointer to state manager
	StateManager* stateManager;

	/// Platform class containing Window/Renderer and other OS dependent data
	Platform* platform;

	///This states name
	std::string stateName;
};