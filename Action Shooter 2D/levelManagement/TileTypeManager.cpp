#include "TileTypeManager.h"
#include "../Utility.h"

TileTypeManager::TileTypeManager(std::string filePath, SDL_Renderer* renderer)
{
	loadTileData(filePath, renderer);
}

TileTypeManager::~TileTypeManager()
{

}

void TileTypeManager::loadTileData(std::string filePath, SDL_Renderer* renderer)
{
	//File loading message
	Utility::log(Utility::I, "Loading tile data.");

	//Open the file using a ifstream
	std::ifstream file(filePath);

	//If the file successfully opens
	if (file.is_open())
	{
		//Load the number of tile groups.
		file >> numOfGroups;

		//loop for the number of tile groups
		for (int i = 0; i < numOfGroups; i++)
		{
			//variables for the loaded string data
			char group;
			std::string filePath;
			Vec2 dimensions;

			//load in the data
			file >> group;
			file >> filePath;
			file >> dimensions.x;
			file >> dimensions.y;

			//store the data
			spritesheets[group] = new Texture(filePath, renderer);
			spriteDimensions[group] = dimensions;
		}

		//Load the number of tile types.
		file >> numOfTypes;

		//loop for the number of tile types
		for (int i = 0; i < numOfTypes; i++)
		{
			//variables for the loaded string data
			char group; 
			std::string iD;
			bool collidable, destructible;
			Vec2 spriteIndex;

			//load in the data
			file >> group;
			file >> iD;
			file >> collidable;
			file >> destructible;
			file >> spriteIndex.x;
			file >> spriteIndex.y;

			//store the data
			tiles[group].push_back(
				new TileType(spritesheets[group], iD, collidable, destructible, spriteIndex, spriteDimensions[group])
				);
		}
		//Close the file
		file.close();

		//File loaded message
		Utility::log(Utility::I, "Tile data loaded.");
	}
	else
	{
		//Error message
		Utility::log(Utility::E, "Unable to open file : " + filePath);
	}
}