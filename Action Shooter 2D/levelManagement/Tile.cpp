#include "Tile.h"

Tile::Tile(Texture* texture, Vec2 pos, Vec2 dimensions, Vec2 spritePos, Vec2 spriteDimensions, TileType* tileType)
	: Entity(texture, pos, dimensions, spritePos, spriteDimensions), tileType(tileType)
{
}

Tile::~Tile()
{
}

void Tile::update(float dt)
{
}

void Tile::render(SDL_Renderer *renderer)
{
	//If the Tile does not have a blank ID then render to the Tile
	if (tileType->getID() != "XX")
	{
		tileType->render(renderer, pos, dimensions);
	}
}
