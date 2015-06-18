#include "State.h"
#include <vector>
#include "../dependencies/SDL.h"

#pragma once

/**
@class StateManager
@brief Manages the creation, switching and function forwarding for States
*/
class StateManager
{
public:

	/**
	@brief Create the State Manager.
	
	@param windowWidth  - Window Width.
	@param windowHeight - Window Height.
	 */
	StateManager(int windowWidth, int windowHeight);

	~StateManager();

	/**
	@brief Add a state on top of the previous state.
	
	@param [in,out] state - The new state.
	 */
	void addState(State* state);

	/**
	@brief Resets the Timer class otherwise conflicts happen
	*/
	void prepareToChangeState();

	/**
	@brief Change to a new state while deleting all previous states.
	
	@param [in,out] state - The new State.
	 */
	void changeState(State* state);

	/**
	@brief Deletes the most recent state 
	*/
	void popLastState();

	//Pass through functions that call the states internal functions

	/**
	@brief Calls the event handler in the current state.
	
	@return true to exit, false to continue.
	 */
	bool eventHandler();

	/**
	@brief Calls the update in the current state.
	
	@param dt - delta time.
	 */
	void update(float dt);

	/** @brief Calls the render for all loaded states. */
	void render();

	//Think these are fine to have public since they are const
	///The Window's Width
	const int WINDOW_WIDTH;

	///The Window's Height
	const int WINDOW_HEIGHT;

private:
	/**
	@brief Deletes all currently loaded states
	*/
	void clearStates();

	///All the currently loaded states
	std::vector<State*> states;

};