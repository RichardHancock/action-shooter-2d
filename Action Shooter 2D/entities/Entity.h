#pragma once

#include "../Vec2.h"
#include "../Texture.h"

/**
@brief Contains all the data and functions dealing with the Entity.
*/
class Entity
{
public:
	/**
	@brief Create the Entity using the size of the Texture as the size of the Entity.
	@param texture A pointer to the Texture.
	@param pos The position of the Entity.
	*/
	Entity(Texture* texture, Vec2 pos);

	/**
	@brief Create the Entity.
	@param texture A pointer to the Texture.
	@param pos The position of the Entity.
	@param dimensions The dimensions of the Entity.
	*/
	Entity(Texture* texture, Vec2 pos, Vec2 dimensions);

	/**
	@brief Create the Entity with a sprite from a spritesheet.
	@param texture A pointer to the Texture.
	@param pos The position of the Entity.
	@param dimensions The dimensions of the Entity.
	@param pos The position of the sprite in the spritesheet.
	@param dimensions The dimensions of the sprite in the spritesheet.
	*/
	Entity(Texture* texture, Vec2 pos, Vec2 dimensions, Vec2 spritePos, Vec2 spriteDimensions);

	/**
	@brief Virtual Tile destructor.
	*/
	virtual ~Entity();

	/**
	@brief A pure virtual function to update the Entity.
	@param dt The delta time.
	*/
	virtual void update(float dt) = 0;

	/**
	@brief A virtual function to render the Entity.
	@param renderer A pointer to the renderer.
	*/
	virtual void render(SDL_Renderer* renderer);

	/**
	@brief Set the position of the Entity.
	@param pos The position of the Entity.
	*/
	void setPosition(Vec2 pos);

	/**
	@brief Set the dimensions of the Entity.
	@param dimensions The dimensions of the Entity.
	*/
	void setDimensions(Vec2 dimensions);

	/**
	@brief Get the position of the Entity.
	@return The position of the Entity.
	*/
	Vec2 getPosition();	

	/**
	@brief Get the dimensions of the Entity.
	@return The dimensions of the Entity.
	*/
	Vec2 getDimensions();

protected:
	///The XY position of the Entity.
	Vec2 pos;
	///The dimensions of the Entity.
	Vec2 dimensions;
	///A pointer to the Texture of the entity.
	Texture* texture;
	///The position of the sprite in the spritesheet.
	Vec2 spritePos;
	///The dimensions of the sprite in the spritesheet.
	Vec2 spriteDimensions;
};