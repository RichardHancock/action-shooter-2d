#include "Tile.h"

Tile::Tile(Vec2 p, Vec2 colRow, std::string tID) : Entity(p)
{
	tv = colRow;
	ID = tID;
}

Tile::~Tile()
{

}

void Tile::update(float dt)
{

}

void Tile::render()
{

}
