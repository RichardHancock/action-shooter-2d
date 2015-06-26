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
		//Load the number of different spritesheets.
		file >> numOfSpritesheets;

		//loop for the number of spritesheets
		for (int i = 0; i < numOfSpritesheets; i++)
		{
			//variables for the loaded string data
			std::string spritesheetID;
			std::string filePath;
			Vec2 dimensions;

			//load in the data
			file >> spritesheetID;
			file >> filePath;
			file >> dimensions.x;
			file >> dimensions.y;

			//store the data
			spritesheets[spritesheetID] = new Texture(filePath, renderer);
			spriteDimensions[spritesheetID] = dimensions;
		}

		//Load the number of tile types.
		file >> numOfTypes;

		//loop for the number of tile types
		for (int i = 0; i < numOfTypes; i++)
		{
			//variables for the loaded string data
			std::string spritesheetID;
			std::string iD;
			bool collidable, destructible;
			Vec2 spriteIndex;

			//load in the data
			file >> spritesheetID;
			file >> iD;
			file >> collidable;
			file >> destructible;
			file >> spriteIndex.x;
			file >> spriteIndex.y;

			//store the data
			tileTypes[iD] = new TileType(spritesheets[spritesheetID], iD, collidable, 
				destructible, spriteIndex, spriteDimensions[spritesheetID]);
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

TileType* TileTypeManager::getTileType(std::string tileTypeID)
{
	return tileTypes[tileTypeID];
}