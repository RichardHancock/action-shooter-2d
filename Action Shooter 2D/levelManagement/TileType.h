#pragma once

#include "../Texture.h"
#include "../Vec2.h"

/**
@brief Creates a TileType Object.
@author Jamie Slowgrove
*/
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
	@brief Gets if the TileType is collidable.
	@return If the TileType is collidable.
	*/
	bool getCollidable();

	/**
	@brief Gets if the TileType is destructible.
	@return If the TileType is destructible.
	*/
	bool getDestructible();

	/**
	@brief Gets a pointer to the TileType Texture.
	@return A pointer to the Texture.
	*/
	Texture* getTexture();

	/**
	@brief Gets the TileType ID.
	@return The TileType ID.
	*/
	std::string getID();

	/**
	@brief Gets the sprites position in the spritesheet.
	@return The sprites position.
	*/
	Vec2 getSpritePos();

	/**
	@brief Gets the sprites dimension in the spritesheet.
	@return The sprites dimensions.
	*/
	Vec2 getSpriteDimensions();

private:
	///A pointer to the spritesheet.
	Texture* spritesheet;
	///The ID of the TileType.
	std::string iD;
	///A boolean for if the TileType is collidable.
	bool collidable;
	///A boolean for if the TileType is destructible.
	bool destructible;
	///The position of the sprite on the spritesheet.
	Vec2 spritePosition;
	///The index position of the sprite on the spritesheet.
	Vec2 spriteIndexPositions;
	///The dimensions of the sprite.
	Vec2 spriteDimensions;
};