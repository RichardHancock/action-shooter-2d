#include "TileType.h"

TileType::TileType(Texture* spritesheet, std::string iD, bool collidable, bool destructible,
	Vec2 spriteIndexPositions, Vec2 spriteDimensions) 
	: spritesheet(spritesheet), iD(iD), collidable(collidable), destructible(destructible),
	spriteIndexPositions(spriteIndexPositions), spriteDimensions(spriteDimensions)
{
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

Texture* TileType::getTexture()
{
	return spritesheet;
}

std::string TileType::getID()
{
	return iD;
}

Vec2 TileType::getSpritePos()
{
	return spritePosition;
}

Vec2 TileType::getSpriteDimensions()
{
	return spriteDimensions;
}