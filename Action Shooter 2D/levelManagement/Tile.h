#pragma once

#include <string>
#include "../entities/Entity.h"
#include "TileType.h"

class Tile : public Entity
{
public:
	/**
	@brief Create the Tile

	@param p - Tile position
	@param colRow - The table value in the map
	@param tID - The ID used to represent the type of tile
	*/
	Tile(Vec2 p, Vec2 colRow, std::string tID);

	~Tile();

	/**
	@brief Update any internal values.

	@param dt - delta time.
	*/
	void update(float dt);

	/**
	@brief Render any sprites relevant to the entity
	*/
	void render();

	/**
	@brief Sets the tile ID

	@param i - The integer to set the tile ID to
	*/
	void setID(int i);

	/**
	@brief Gets the tile ID

	@return Tile ID
	*/
	int getID();


private:
	///The tile size
	int TS;

	///The ID that represents the type of tile
	std::string ID;

	///Reference to tile type
	TileType *type;

	///The tile table value - row, column
	Vec2 mapIndexPosition;

};