#include "Tile.h"

Tile::Tile(Vec2 p, Vec2 tv, int ID) : Entity(p)
{
	this->tv = tv;
	this->ID = ID;
}

Tile::~Tile()
{

}

