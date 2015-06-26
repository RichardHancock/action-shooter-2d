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
	///The number of different spritesheets.
	int numOfSpritesheets;
	///The number of tile types.
	int numOfTypes;
	///The loaded tiles. Contains the tile data.
	std::unordered_map<std::string, TileType*> tileTypes;
	///The spritesheets.
	std::unordered_map<std::string, Texture*> spritesheets;
	///The dimensions of the sprites for each spritesheet.
	std::unordered_map<std::string, Vec2> spriteDimensions;

	/**
	@brief Loads the tile data from the file.
	@param filePath The file path of the tiles data.
	@param renderer A pointer to the renderer.
	*/
	void loadTileData(std::string filePath, SDL_Renderer* renderer);

	/**
	@brief Gets a pointer to the TileType associated with the ID.
	@param tileTypeID The ID of wanted TileType.
	@param A pointer to the TileType.
	*/
	TileType* getTileType(std::string tileTypeID);
};