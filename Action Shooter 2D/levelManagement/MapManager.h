#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include "Tile.h"

class MapManager {
public:
	/**
	@brief Creates the map manager to load in map files
	@param filepath - The path to the file which holds the map data
	*/
	MapManager(std::string filepath);
	~MapManager();

private:
	/**
	@brief Loads in the map data
	@param filepath - The path to the file which holds the map data
	*/
	void loadMapData(std::string filepath);

	///A vector to hold all of the layer types on specific layers
	std::vector<char> layerType;

	///A 3D vector that holds all tile data according to layer and columnrow position
	std::vector<std::vector<std::vector<Tile*>>> mapTiles;


};