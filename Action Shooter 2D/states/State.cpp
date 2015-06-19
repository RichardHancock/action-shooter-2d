#include "State.h"
#include "../Utility.h"

State::State(StateManager* stateManager, Platform* platform)
	:stateManager(stateManager), platform(platform), active(false)
{

}

void State::startLoading()
{
	active = true;
	load();

	Utility::log(Utility::I, stateName + " was loaded");
}

void State::startUnloading()
{
	active = false;
	unload();

	Utility::log(Utility::I, stateName + " was unloaded");
}