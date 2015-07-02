#include "MapManager.h"
#include "../Utility.h"

MapManager::MapManager(std::string filePath, TileTypeManager* tileTypeManager)
{
	loadMapData(filePath, tileTypeManager);
}

MapManager::~MapManager()
{
}

void MapManager::loadMapData(std::string filePath, TileTypeManager* tileTypeManager)
{
	//A vector to hold all of the layer IDs.
	std::vector<std::string> layerIDs;

	//A 3D vector that contains all of the tiles. [Layer ID][Y Index][X Index]
	std::unordered_map<std::string, std::vector<std::vector<Tile*>>> mapTiles;

	Utility::log(Utility::I, "Loading map data : " + filePath);

	std::ifstream mapFile(filePath);

	if (mapFile.is_open())
	{
		std::string mapID;
		Vec2 mapIndexDimensions;
		int numberOfLayers;
		Vec2 tileDimensions;

		mapFile >> mapID;
		mapFile >> mapIndexDimensions.x;
		mapFile >> mapIndexDimensions.y;
		mapFile >> numberOfLayers;
		mapFile >> tileDimensions.x;
		mapFile >> tileDimensions.y;

		//store the map ID
		mapIDs.push_back(mapID);

		for (int i = 0; i < numberOfLayers; i++)
		{
			//Store the ID of the layer
			std::string layerID;
			mapFile >> layerID;
			layerIDs.push_back(layerID);

			for (int y = 0; y < mapIndexDimensions.y; y++)
			{
				std::vector<Tile*> tiles;
				mapTiles[layerID].push_back(tiles);
				for (int x = 0; x < mapIndexDimensions.x; x++)
				{
					//Get the tile
					std::string tileID;
					mapFile >> tileID;

					//Get the data to load into the new tile
					TileType* tileType = tileTypeManager->getTileType(tileID);
					Vec2 spriteDimensions = tileType->getSpriteDimensions();
					Vec2 spritePos = tileType->getSpritePos();
					Texture* tileTexture = tileType->getTexture();

					//Store tile
					mapTiles[layerID][y].push_back(
						new Tile(tileTexture, Vec2((x * tileDimensions.x), (y * tileDimensions.y)), tileDimensions, spritePos, spriteDimensions, tileType)
						);
				}
			}
		}
		mapFile.close();

		//Store the map
		maps[mapID] = new Map(mapTiles, layerIDs);

		Utility::log(Utility::I, "Map data loaded");
	}
	else 
	{
		//Error
		Utility::log(Utility::E, "Unable to open map file : " + filePath);
	}
}

Map* MapManager::getMap(std::string mapID)
{
	return maps[mapID];
}
