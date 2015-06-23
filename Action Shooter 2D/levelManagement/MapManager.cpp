#include "MapManager.h"
#include "../Utility.h"

MapManager::MapManager(std::string filepath)
{
	loadMapData(filepath);
}

MapManager::~MapManager()
{

}

void MapManager::loadMapData(std::string filepath)
{
	Utility::log(Utility::I, "Loading map data");

	std::ifstream mapFile(filepath);

	if (mapFile.is_open())
	{
		std::string mID;
		Vec2 dimen;
		int numLayers;

		mapFile >> mID;
		mapFile >> dimen.x;
		mapFile >> dimen.y;
		mapFile >> numLayers;

		for (int i = 0; i < numLayers; i++)
		{
			char type;
			mapFile >> type;

			layerType.push_back(type);

			//create new instances of the layer portion of the map
			std::vector<std::vector<Tile*>> layers;
			mapTiles.push_back(layers);
			//use y first to go through every value of each row
			for (int j = 0; j < dimen.y; j++)
			{
				//create new instance of tile portion of the map
				std::vector<Tile*> tiles;
				mapTiles[i].push_back(tiles);
				for (int k = 0; k < dimen.x; k++)
				{
					std::string tileID;

					mapFile >> tileID;

					//create a new tile and push it onto the 
					Tile *mTile = new Tile(Vec2(k, j), Vec2(k, j), tileID);
					mapTiles[i][j].push_back(mTile);
				}
			}
		}
		mapFile.close();

		Utility::log(Utility::I, "Map data loaded");
	}
	else {
		//Error
		Utility::log(Utility::E, "Unable to open map file : " + filepath);
	}



}