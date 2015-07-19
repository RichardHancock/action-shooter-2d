#pragma once

#include "../entities/Entity.h"
#include "Tile.h"
#include "../entities/creatures/Creature.h"
#include <Vector>

/**
@brief Contains all the data and functions dealing with the Map objects.
*/
class Map
{
public:
	/**
	@brief Creates the Map for the level.
	@param mapTiles The Tiles in the Map.
	@param layerIDs The list of the layer ID's.
	*/
	Map(std::unordered_map<std::string, std::vector<std::vector<Tile*>>> mapTiles, std::vector<Creature*> mapCreatures, std::vector<std::string> layerIDs);

	/**
	@brief Map destructor.
	*/
	~Map();

	/**
	@brief Update the Map.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief Render the Tile objects in the map.
	@param renderer A pointer to the renderer.
	*/
	void render(SDL_Renderer* renderer);

private:
	///A vector to hold all of the layer IDs.
	std::vector<std::string> layerIDs;
	///A 3D vector that contains all of the tiles. [Layer ID][Y Index][X Index]
	std::unordered_map<std::string, std::vector<std::vector<Tile*>>> mapTiles;

	//An unordered map that contains all of the creatures. [Layer ID][Y Index][X Index]
	//std::unordered_map<std::string, Creature*> mapCreatures;

	///A vector of all creatures
	std::vector<Creature*> mapCreatures;
};