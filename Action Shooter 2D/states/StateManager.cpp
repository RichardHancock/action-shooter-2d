#include "StateManager.h"
#include "State.h"
#include "../Utility.h"

StateManager::StateManager()
{

}

StateManager::~StateManager()
{
	clearStates();
}

void StateManager::clearStates()
{
	for (auto s : states)
	{
		s->startUnloading();
		delete s;
	}
	states.clear();
}

void StateManager::addState(State* state)
{
	states.push_back(state);
	Utility::log(Utility::I, "StateManager: Switched to the " + state->getStateName());
	state->startLoading();
	
}

void StateManager::prepareToChangeState()
{
	//Stop Music and Clear the timers
	Utility::Timer::cleanup();
}

void StateManager::changeState(State* state)
{
	clearStates();
	addState(state);
}

void StateManager::popLastState()
{
	states.back()->startUnloading();
	delete states.back();
	states.pop_back();
}

bool StateManager::eventHandler()
{
	if (!states.empty() && states.back() != nullptr && states.back()->isActive())
	{
		return states.back()->eventHandler();
	}
	else
	{
		return false;
	}
}

void StateManager::update(float dt)
{
	if (!states.empty() && states.back() != nullptr && states.back()->isActive())
		states.back()->update(dt);
}

void StateManager::render()
{
	for (int i = 0; i < (int)states.size(); i++)
	{
		if (states[i] != nullptr && states[i]->isActive())
			states[i]->render();
	}
}