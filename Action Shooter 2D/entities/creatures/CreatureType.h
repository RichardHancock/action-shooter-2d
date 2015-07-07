#pragma once

#include "../../Vec2.h"
#include "../../Texture.h"

/**
@brief Creates a CreatureType object
*/

class CreatureType
{
public:
	/**
	@brief CreatureType constructor
	@param spritesheet A pointer to the Creature spritesheet
	@param creatureName The name of the creature
	@param spriteDimensions The dimensions of the creature
	@param weight The weight of the creature
	@param speed The speed of the creature
	@param maxSpeed The maximum speed this creature can move by
	@param strength The strength of the creature
	@param maxHealth The number of hitpoints this creature starts off with
	*/
	CreatureType(Texture* spritesheet, std::string creatureName, Vec2 spriteDimensions, 
		float weight, float speed, float maxSpeed, float strength, float maxHealth);
	~CreatureType();

	void render(SDL_Renderer *renderer, Vec2 pos, int state, int frame);

	/**
	@brief Gets the weight of the creature
	@return The weight of of the creature
	*/
	float getWeight();

	/**
	@brief Gets the speed of the creature
	@return The speed of the creature
	*/
	float getSpeed();

	/**
	@brief Gets the maximum speed this creature can move by
	@return The max speed this creature can move by
	*/
	float getMaxSpeed();

	/**
	@brief Gets the strength of the creature
	@return The strength of the creature
	*/
	float getStrength();

	/**
	@brief Gets the maximum health of the creature
	@return The maximum health of the creature
	*/
	float getMaxHealth();

private:
	///A pointer to the spritesheet.
	Texture* spritesheet;

	///The dimensions of the sprite.
	Vec2 spriteDimensions;

	///The name of the creature
	std::string creatureName;

	///The weight of the creature
	float weight;

	///The speed of the creature
	float speed;

	///The maximum speed this creature can move by
	float maxSpeed;

	///The strength of the creature
	float strength;

	///The number of hitpoints this creature starts off with
	float maxHealth;

	


};