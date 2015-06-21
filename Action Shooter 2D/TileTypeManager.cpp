#include "TileTypeManager.h"

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
	std::cout << "Loading tile data." << std::endl;

	//Open the file using a ifstream
	std::ifstream file(filePath);

	//If the file successfully opens
	if (file.is_open())
	{
		//Load the number of tile groups.
		std::string loadedString;
		file >> loadedString;
		numOfGroups = std::stoi(loadedString);

		//loop for the number of tile groups
		for (int i = 0; i < numOfGroups; i++)
		{
			//variables for the loaded string data
			std::string group, filePath, xDimension, yDimension;

			//load in the data
			file >> group;
			file >> filePath;
			file >> xDimension;
			file >> yDimension;

			//store the data
			spritesheets[group.c_str()[0]] = new Texture(filePath, renderer);
			spriteDimensions[group.c_str()[0]] = Vec2(std::stoi(xDimension), std::stoi(yDimension));
			tiles[group.c_str()[0]];
		}

		//Load the number of tile types.
		file >> loadedString;
		numOfTypes = std::stoi(loadedString);

		//loop for the number of tile types
		for (int i = 0; i < numOfTypes; i++)
		{
			//variables for the loaded string data
			std::string group, iD, collidableString, destructibleString, xIndex, yIndex;

			//load in the data
			file >> group;
			file >> iD;
			file >> collidableString;
			file >> destructibleString;
			file >> xIndex;
			file >> yIndex;

			//store the data
			bool collidable, destructible;
			if (collidableString.c_str()[0] == 'T'){ collidable = true; }
			else{ collidable = false; }
			if (destructibleString.c_str()[0] == 'T'){ destructible = true; }
			else{ destructible = false; }
			tiles[group.c_str()[0]].push_back(
				new TileType(spritesheets[group.c_str()[0]], iD, collidable, destructible,
				Vec2(std::stof(xIndex), std::stof(yIndex)), spriteDimensions[group.c_str()[0]])
				);
		}
		//Close the file
		file.close();

		//File loaded message
		std::cout << "Tile data loaded." << std::endl << std::endl;
	}
	else
	{
		//Error message
		std::cout << "Unable to open file : " + filePath;
	}
}