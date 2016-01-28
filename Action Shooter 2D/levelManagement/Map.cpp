#include "Map.h"

Map::Map(std::unordered_map<std::string, std::vector<std::vector<Tile*>>> mapTiles, std::vector<Creature*> mapCreatures, std::vector<std::string> layerIDs, Vec2 spawnPoint) : mapTiles(mapTiles), mapCreatures(mapCreatures), layerIDs(layerIDs), spawnPoint(spawnPoint)
{
}

Map::~Map()
{
}

void Map::update(float dt)
{
}

void Map::render(SDL_Renderer* renderer)
{
	

	//Load in all the map data
	//Loop through all of the Layer ID's
	for (unsigned int i = 0; i < layerIDs.size(); i++)
	{
		//Loop through all the map tiles
		for (unsigned int y = 0; y < mapTiles[layerIDs[i]].size(); y++)
		{
			for (unsigned int x = 0; x < mapTiles[layerIDs[i]][y].size(); x++)
			{
				mapTiles[layerIDs[i]][y][x]->render(renderer);
			}
		}
	}

	//load in the creature data

	for (unsigned int i = 0; i < mapCreatures.size(); i++)
	{
		mapCreatures[i]->render(renderer);
	}
	

	//load in the player data

	if (playerLoaded)
	{
		player->render(renderer);
	}
}

void Map::loadPlayer(CharacterType *pt)
{
	player = new Character(pt->getTexture(), spawnPoint, pt);

	playerLoaded = true;
}