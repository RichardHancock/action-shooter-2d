#pragma once

#include "../Entity.h"
#include "CreatureType.h"

class Creature : public Entity
{
public:
	/**
	@brief Create the Creature using the size of the Texture as the size of the Creature.
	@param texture A pointer to the Texture.
	@param pos The position of the Creature.
	*/
	Creature(Texture* texture, Vec2 pos, CreatureType *creatureType);

	/**
	@brief Create the Creature.
	@param texture A pointer to the Texture.
	@param pos The position of the Creature.
	@param dimensions The dimensions of the Creature.
	*/
	Creature(Texture* texture, Vec2 pos, Vec2 dimensions, CreatureType *creatureType);

	/**
	@brief Create the Creature with a sprite from a spritesheet.
	@param texture A pointer to the Texture.
	@param pos The position of the Creature.
	@param dimensions The dimensions of the Creature.
	@param spriteDimensions The dimensions of the sprite in the spritesheet.
	*/
	Creature(Texture* texture, Vec2 pos, Vec2 dimensions, Vec2 spriteDimensions, CreatureType *creatureType);

	~Creature();

	/**
	@brief Update the Creature.
	@param dt The delta time.
	*/
	virtual void update(float dt);


	/**
	@brief Render the Creature.
	@param renderer A pointer to the renderer.
	*/
	virtual void render(SDL_Renderer* renderer);


private:
	///Reference to CreatureType
	CreatureType *creatureType;

	///The state of the creature - idle, attacking etc
	int creatureState;

	///The velocity of the creature - direction and current speed
	Vec2 velocity;

	///The state this creature is in
	int state;

	///The frame of the state this creature is in
	int frame;


};