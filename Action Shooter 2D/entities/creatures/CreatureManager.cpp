#include "CreatureManager.h"
#include "../../Utility.h"

CreatureManager::CreatureManager(std::string creaFilePath, std::string charFilePath, SDL_Renderer *renderer)
{
	//load enemy data
	loadCreatureData(creaFilePath, renderer);

	//load character data
	loadCharacterData(charFilePath, renderer);

	//load npc data
}

CreatureManager::~CreatureManager()
{

}

void CreatureManager::loadCreatureData(std::string filePath, SDL_Renderer *renderer)
{

	Utility::log(Utility::I, "Loading all creatures type data : " + filePath);

	std::ifstream creatureList(filePath);

	if (creatureList.is_open())
	{
		int numCreatures;

		creatureList >> numCreatures;

		for (int i = 0; i < numCreatures; i++)
		{
			std::string ID;
			std::string creatureFile;

			creatureList >> ID;
			creatureList >> creatureFile;

			Utility::log(Utility::I, "Loading creature data : " + creatureFile);
			std::ifstream creature(creatureFile);

			if (creature.is_open())
			{
				std::string spritesheetPath;
				std::string creatureName;

				Vec2 creatureDimensions;

				float creatureWeight;
				float creatureSpeed;
				float creatureMaxSpeed;
				float creatureStrength;
				float creatureMaxHealth;

				creature >> spritesheetPath;
				creature >> creatureName;
				creature >> creatureDimensions.x;
				creature >> creatureDimensions.y;

				creature >> creatureWeight;
				creature >> creatureSpeed;
				creature >> creatureMaxSpeed;
				creature >> creatureStrength;
				creature >> creatureMaxHealth;

				/*
				WILL NEED TO GET ANIMATION DATA
				*/

				Texture* creatureSpriteSheet = new Texture(spritesheetPath, renderer);

				creatureTypes[ID] = new CreatureType(creatureSpriteSheet, ID, creatureName, creatureDimensions, 
					creatureWeight, creatureSpeed, creatureMaxSpeed, creatureStrength, creatureMaxHealth);


				creature.close();

				//File loaded message
				Utility::log(Utility::I, "Creature data loaded.");

			}
			else {
				//Error message
				Utility::log(Utility::E, "Unable to open creature file : " + creatureFile);
			}
		}
	}
	else 
	{
		//Error message
		Utility::log(Utility::E, "Unable to open file : " + filePath);
	}


}


CreatureType* CreatureManager::getCreatureType(std::string creatureID)
{
	return creatureTypes[creatureID];
}

void CreatureManager::loadCharacterData(std::string filePath, SDL_Renderer *renderer)
{
	Utility::log(Utility::I, "Loading all creatures type data : " + filePath);

	std::ifstream charList(filePath);

	if (charList.is_open())
	{
		int numCharacters;

		charList >> numCharacters;

		for (int i = 0; i < numCharacters; i++)
		{
			std::string ID;
			std::string characterFile;

			charList >> ID;
			charList >> characterFile;

			Utility::log(Utility::I, "Loading character data : " + characterFile);
			std::ifstream character(characterFile);

			if (character.is_open())
			{
				std::string spritesheetPath;
				std::string characterName;
			

				Vec2 characterDimensions;

				float characterWeight;
				float characterSpeed;
				float characterMaxSpeed;
				float characterStrength;
				float characterMaxHealth;

				character >> spritesheetPath;
				character >> characterName;
				character >> characterDimensions.x;
				character >> characterDimensions.y;

				character >> characterWeight;
				character >> characterSpeed;
				character >> characterMaxSpeed;
				character >> characterStrength;
				character >> characterMaxHealth;

				/*
				WILL NEED TO GET ANIMATION DATA
				*/

				Texture* characterSpriteSheet = new Texture(spritesheetPath, renderer);

				characterTypes[ID] = new CharacterType(characterSpriteSheet, ID, characterName, characterDimensions,
					characterWeight, characterSpeed, characterMaxSpeed, characterStrength, characterMaxHealth);


				character.close();

				//File loaded message
				Utility::log(Utility::I, "Creature data loaded.");

			}
			else {
				//Error message
				Utility::log(Utility::E, "Unable to open creature file : " + characterFile);
			}
		}
	}


}


CharacterType* CreatureManager::getCharacterType(std::string charID)
{
	return characterTypes[charID];
}