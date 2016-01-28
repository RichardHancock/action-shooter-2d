#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include "../../Vec2.h"
#include "Character.h"

/**
@brief Contains all the data and functions to manage the Creatures
*/
class CharacterManager {
public:
	/**
	@brief Creates the CreatureManager to load in the creature files
	@param filePath The path to the file which holds the the links to the creature data.
	@param renderer A pointer to the renderer
	*/
	CharacterManager(std::string filepath, SDL_Renderer *renderer);
	~CharacterManager();

	/**
	@brief Gets the Creature type
	@param creatureID The ID of the wanted creature type
	@return A pointer to the creature type
	*/
	CharacterManager* getCreatureType(std::string creatureID);


private:
	///An unordered map of the creature types
	std::unordered_map<std::string, CharacterManager*> creatureTypes;

	/**
	@brief Creates the MapManager to load in the Map files
	@param filePath The path to the file which holds the the links to the creature data.
	@param renderer A pointer to the renderer
	*/
	void loadCreatureData(std::string filepath, SDL_Renderer *renderer);
};