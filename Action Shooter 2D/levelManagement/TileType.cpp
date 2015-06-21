#include "TileType.h"

TileType::TileType(Texture* spritesheet, std::string iD, bool collidable, bool destructible,
	Vec2 spriteIndexPositions, Vec2 spriteDimensions)
{
	this->spritesheet = spritesheet;
	this->iD = iD;
	this->collidable = collidable;
	this->spriteIndexPositions = spriteIndexPositions;
	this->spriteDimensions = spriteDimensions;
}

TileType::~TileType()
{

}

void TileType::render(SDL_Renderer* renderer, Vec2 pos, Vec2 dimensions)
{
	int srcX = (int)(spriteIndexPositions.x * spriteDimensions.x);
	int srcY = (int)(spriteIndexPositions.y * spriteDimensions.y);

	spritesheet->pushSpriteToScreen(renderer, (int)pos.x, (int)pos.y, srcX, srcY,
		(int)spriteDimensions.x, (int)spriteDimensions.y, (int)dimensions.x, (int)dimensions.y);
}

bool TileType::getCollidable()
{
	return collidable;
}

bool TileType::getDestructible()
{
	return destructible;
}