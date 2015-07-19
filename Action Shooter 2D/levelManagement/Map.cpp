#include "Map.h"

Map::Map(std::unordered_map<std::string, std::vector<std::vector<Tile*>>> mapTiles, std::vector<Creature*> mapCreatures, std::vector<std::string> layerIDs) : mapTiles(mapTiles), mapCreatures(mapCreatures), layerIDs(layerIDs)
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

	for (unsigned int i = 0; i < mapCreatures.size(); i++)
	{
		mapCreatures[i]->render(renderer);
	}
}