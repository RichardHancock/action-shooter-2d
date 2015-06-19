#pragma once

#include "Entity.h"

class Tile : public Entity
{
public:
	/**
	@brief Create the Tile

	@param
	*/
	Tile(Vec2 p, Vec2 tv, int ID);

	~Tile();

	void setID(int i);
	int getID();


private:
	///The tile size
	int TS;

	///The ID
	int ID;

	///The tile table value - row, column
	Vec2 tv;

};