#include "Map.h"

Map::Map(Vec2 p, Vec2 d) : Entity(p,d)
{
	createBlankMap();
}

Map::~Map()
{

}

void Map::update(float dt)
{

}

void Map::render()
{

}

void Map::createBlankMap()
{
	for (int i = 0; i < dimen.x; i++)
	{
		std::vector<Tile*> tmp;
		mapLayerOne.push_back(tmp);
		std::vector<Tile*> tmp2;
		mapLayerTwo.push_back(tmp2);

		for (int j = 0; j < dimen.y; j++)
		{
			Tile *t = new Tile(Vec2(i, j), Vec2(i, j), 0);
			mapLayerOne[i].push_back(t);
		}
	}
}

