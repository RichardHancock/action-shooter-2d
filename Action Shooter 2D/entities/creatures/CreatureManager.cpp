#include "CreatureManager.h"
#include "../../Utility.h"

CreatureManager::CreatureManager(std::string filePath, SDL_Renderer *renderer)
{
	loadCreatureData(filePath, renderer);
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

				creatureTypes[ID] = new CreatureType(creatureSpriteSheet, creatureName, creatureDimensions, 
					creatureWeight, creatureSpeed, creatureSpeed, creatureStrength, creatureMaxHealth);


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
