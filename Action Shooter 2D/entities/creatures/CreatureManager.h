#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include "../../Vec2.h"
#include "CreatureType.h"

class CreatureManager {
public:
	CreatureManager(std::string filepath, SDL_Renderer *renderer);
	~CreatureManager();

	
private:

	std::unordered_map<std::string, CreatureType*> creatureTypes;
	void loadCreatureData(std::string filepath, SDL_Renderer *renderer);
};