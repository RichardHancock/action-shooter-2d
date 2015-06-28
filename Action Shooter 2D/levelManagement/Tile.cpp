#include "Tile.h"

Tile::Tile(Vec2 p, Vec2 colRow, std::string tID, TileTypeManager *ttManager) : Entity(p)
{
	mapIndexPosition = colRow;
	ID = tID;

	tTypeManager = ttManager;

	type = tTypeManager->getTileType(ID);

	dimen = Vec2(32, 32);

	
}

Tile::~Tile()
{

}

void Tile::update(float dt)
{

}

void Tile::render(SDL_Renderer *renderer)
{
	if (ID != "XX")
	{
		type->render(renderer, pos, dimen);
	}
}
