#pragma once

#include "Texture.h"
#include "Vec2.h"

class TileType
{
public:
	/**
	@brief TileType constructor.
	@param spritesheet A pointer to the Tile spritesheet.
	@param iD The ID of the TileType.
	@param collidable A boolean for if the TileType is collidable.
	@param destructible A boolean for if the TileType is destructible.
	@param spriteIndexPositions The index positions of the TileType sprite on the spritesheet.
	@param spriteDimensions The dimensions of the TileType sprite on the spritesheet.
	*/
	TileType(Texture* spritesheet, std::string iD, bool collidable, bool destructible, 
		Vec2 spriteIndexPositions, Vec2 spriteDimensions);

	/**
	@brief TileType destructor.
	*/
	~TileType();

	/**
	@brief Render the tile sprite.
	@param renderer A pointer to the renderer.
	@param pos The position on the screen for the sprite.
	@param dimensions The dimensions on the screen for the sprite.
	*/
	void render(SDL_Renderer* renderer, Vec2 pos, Vec2 dimensions);

	/**
	@brief Getter # If the TileType is collidable.
	@return If the TileType is collidable.
	*/
	bool getCollidable();

	/**
	@brief Getter # If the TileType is destructible.
	@return If the TileType is destructible.
	*/
	bool getDestructible();

private:
	///A pointer to the spritesheet.
	Texture* spritesheet;
	///The ID of the TileType.
	std::string iD;
	///A boolean for if the TileType is collidable.
	bool collidable;
	///A boolean for if the TileType is destructible.
	bool destructible;
	///The index position of the sprite on the spritesheet.
	Vec2 spriteIndexPositions;
	///The dimensions of the sprite.
	Vec2 spriteDimensions;
};