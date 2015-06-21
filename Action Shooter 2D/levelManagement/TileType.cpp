#include "TileType.h"

TileType::TileType(Texture* spritesheet, std::string iD, bool collidable, bool destructible,
	Vec2 spriteIndexPositions, Vec2 spriteDimensions)
{
	this->spritesheet = spritesheet;
	this->iD = iD;
	this->collidable = collidable;
	this->destructible = destructible;
	this->spriteIndexPositions = spriteIndexPositions;
	this->spriteDimensions = spriteDimensions;
	spritePosition = spriteIndexPositions * spriteDimensions;
}

TileType::~TileType()
{

}

void TileType::render(SDL_Renderer* renderer, Vec2 pos, Vec2 dimensions)
{
	spritesheet->pushSpriteToScreen(renderer, pos, dimensions, spritePosition, spriteDimensions);
}

bool TileType::getCollidable()
{
	return collidable;
}

bool TileType::getDestructible()
{
	return destructible;
}