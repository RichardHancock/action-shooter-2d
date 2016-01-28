#include "MapManager.h"
#include "../Utility.h"

MapManager::MapManager(std::string filePath, TileTypeManager* tileTypeManager, CreatureManager* creatureManager)
{
	loadMapData(filePath, tileTypeManager, creatureManager);
}

MapManager::~MapManager()
{
}

void MapManager::loadMapData(std::string filePath, TileTypeManager* tileTypeManager, CreatureManager* creatureManager)
{
	//A vector to hold all of the layer IDs.
	std::vector<std::string> layerIDs;

	//A 3D vector that contains all of the tiles. [Layer ID][Y Index][X Index]
	std::unordered_map<std::string, std::vector<std::vector<Tile*>>> mapTiles;
	//std::unordered_map<std::string, std::vector<std::vector<Creature*>>> mapCreatures;
	std::vector<Creature*> mapCreatures;

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
				if (layerID == "O" || layerID == "B")
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
				else if (layerID == "C")
				{
					//std::vector<Creature*> creatures;
					//mapCreatures[layerID].push_back(creatures);
					for (int x = 0; x < mapIndexDimensions.x; x++)
					{
						//Get the creature
						std::string creatureID;
						mapFile >> creatureID;

						if (creatureID != "XX")
						{
							Vec2 pos = Vec2((x * tileDimensions.x), (y * tileDimensions.y));

							CreatureType* creatureType = creatureManager->getCreatureType(creatureID);
							Vec2 spriteDimensions = creatureType->getSpriteDimensions();
							Texture* creatureTexture = creatureType->getTexture();

							mapCreatures.push_back(
								new Creature(creatureTexture, pos, spriteDimensions, creatureType));
						}
					}
				}
				
			}
		}

		std::string p;
		Vec2 playerCoords;
		mapFile >> p;

		if (p == "P")
		{
			mapFile >> playerCoords.x;
			mapFile >> playerCoords.y;
			Utility::log(Utility::I, "Player spawn coordinates: X: " + Utility::floatToString(playerCoords.x) + " Y: " + Utility::floatToString(playerCoords.y));
		}
		else {
			Utility::log(Utility::E,"Shit, we're corrupt");
		}
		mapFile.close();

		//Store the map
		maps[mapID] = new Map(mapTiles, mapCreatures, layerIDs, playerCoords);

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
