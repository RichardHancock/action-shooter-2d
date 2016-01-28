#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include "../../Vec2.h"
#include "CharacterType.h"
#include "Character.h"
#include "CreatureType.h"
#include "Creature.h"

/**
@brief Contains all the data and functions to manage the Creatures
*/
class CreatureManager {
public:
	/**
	@brief Creates the CreatureManager to load in the creature files
	@param filePath The path to the file which holds the the links to the creature data.
	@param renderer A pointer to the renderer
	*/
	CreatureManager(std::string creaFilePath, std::string charFilePath, SDL_Renderer *renderer);
	~CreatureManager();

	/**
	@brief Gets the Creature type
	@param creatureID The ID of the wanted creature type
	@return A pointer to the creature type
	*/
	CreatureType* getCreatureType(std::string creatureID);

	/**
	@brief Gets the Character type
	@param creatureID The ID of the wanted character type
	@return A pointer to the character type
	*/
	CharacterType* getCharacterType(std::string creatureID);

	
private:
	///An unordered map of the creature types
	std::unordered_map<std::string, CreatureType*> creatureTypes;

	///An unordered map of the different characters
	std::unordered_map<std::string, CharacterType*> characterTypes;

	/**
	@brief Loads the creature data
	@param filePath The path to the file which holds the the links to the creature data.
	@param renderer A pointer to the renderer
	*/
	void loadCreatureData(std::string filePath, SDL_Renderer *renderer);

	/**
	@brief Loads the playable character data
	@param filePath The path to the file which holds the the links to the creature data.
	@param renderer A pointer to the renderer
	*/
	void loadCharacterData(std::string filePath, SDL_Renderer *renderer);

};