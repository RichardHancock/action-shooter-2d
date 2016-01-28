#pragma once

#include "../../Vec2.h"
#include "../../Texture.h"
#include "../../Utility.h"

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
	CreatureType(Texture* spritesheet, std::string ID, std::string creatureName, Vec2 spriteDimensions,
		float weight, float speed, float maxSpeed, float strength, float maxHealth);
	~CreatureType();

	/**
	@brief Render the Creature.
	@param renderer A pointer to the renderer.
	@param pos The position on the screen for the sprite.
	@param dimensions The dimensions on the screen for the sprite.
	@param state The state this creature is in
	@param frame The frame of the state this creature is in
	*/
	void render(SDL_Renderer *renderer, Vec2 pos, Vec2 dimensions, int state, int frame);

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
	@brief Gets the sprites dimension in the spritesheet.
	@return The sprites dimensions.
	*/
	Vec2 getSpriteDimensions();

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

protected:
	///A pointer to the spritesheet.
	Texture* spritesheet;

	///The ID of the TileType.
	std::string ID;

	///The dimensions of the sprite in the file.
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