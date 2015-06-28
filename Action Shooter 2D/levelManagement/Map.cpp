#include "Map.h"

Map::Map(Vec2 p, Vec2 d) : Entity(p,d)
{
	createBlankMap();
}

Map::Map(std::vector<std::vector<std::vector<Tile*>>> mapData) : Entity(Vec2(0))
{
	mapTiles = mapData;
}

Map::~Map()
{

}

void Map::update(float dt)
{

}

void Map::render(SDL_Renderer *renderer)
{
	for (int i = 0; i < mapTiles.size(); i++)
	{
		for (int j = 0; j < mapTiles[i].size(); j++)
		{
			for (int k = 0; k < mapTiles[i][j].size(); k++)
			{
				mapTiles[i][j][k]->render(renderer);
			}
		}
	}
}

void Map::createBlankMap()
{
	/*
	for (int i = 0; i < dimen.x; i++)
	{
		std::vector<Tile*> tmp;
		mapLayerOne.push_back(tmp);
		std::vector<Tile*> tmp2;
		mapLayerTwo.push_back(tmp2);

		for (int j = 0; j < dimen.y; j++)
		{
			Tile *t = new Tile(Vec2(i, j), Vec2(i, j), "XX");
			mapLayerOne[i].push_back(t);
		}
	}*/
}

