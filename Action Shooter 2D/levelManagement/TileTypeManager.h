#pragma once

#include "TileType.h"
#include "../Texture.h"
#include "../Vec2.h"
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream> 

/**
@brief Creates a TileTypeManager for dealing with the TileType objects.
@author Jamie Slowgrove
*/
class TileTypeManager
{
public:
	/**
	@brief TileTypeManager constructor.
	@param filePath The file path of the tiles data.
	@param renderer A pointer to the renderer.
	*/
	TileTypeManager(std::string filePath, SDL_Renderer* renderer);

	/**
	@brief TileManager destructor.
	*/
	~TileTypeManager();

private:
	///The number of tile groups.
	int numOfGroups;
	///The number of tile types.
	int numOfTypes;
	///The loaded tiles. Contains the tile data for each group, e.g. Background Tiles(B), Objects (O), etc.
	std::unordered_map<char, std::vector<TileType*>> tiles;
	///The spritesheets for each group, e.g. Background Tiles(B), Objects (O), etc.
	std::unordered_map<char, Texture*> spritesheets;
	///The dimensions of the sprites for each group, e.g. Background Tiles(B), Objects (O), etc.
	std::unordered_map<char, Vec2> spriteDimensions;

	/**
	@brief Loads the tile data from the file.
	@param filePath The file path of the tiles data.
	@param renderer A pointer to the renderer.
	*/
	void loadTileData(std::string filePath, SDL_Renderer* renderer);
};