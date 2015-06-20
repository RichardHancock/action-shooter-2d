#pragma once

#include "Entity.h"

class Tile : public Entity
{
public:
	/**
	@brief Create the Tile

	@param Vec2 p - Tile position
	@param Vec2 colRow - The table value in the map
	@param int tID - The ID used to represent the type of tile
	*/
	Tile(Vec2 p, Vec2 colRow, int tID);

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
	int ID;

	///The tile table value - row, column
	Vec2 tv;

};