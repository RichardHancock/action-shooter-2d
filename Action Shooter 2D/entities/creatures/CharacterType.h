#pragma once

#include "../../Vec2.h"
#include "../../Texture.h"
#include "../../Utility.h"


class CharacterType
{
public:
	CharacterType(Texture* spritesheet, std::string ID, std::string creatureName, Vec2 spriteDimensions,
		float weight, float speed, float maxSpeed, float strength, float maxHealth);
	~CharacterType();

	/**
	@brief Render the Character.
	@param renderer A pointer to the renderer.
	@param pos The position on the screen for the sprite.
	@param dimensions The dimensions on the screen for the sprite.
	@param state The state this character is in
	@param frame The frame of the state this character is in
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
	@brief Gets the weight of the character
	@return The weight of of the character
	*/
	float getWeight();

	/**
	@brief Gets the speed of the character
	@return The speed of the character
	*/
	float getSpeed();

	/**
	@brief Gets the maximum speed this character can move by
	@return The max speed this character can move by
	*/
	float getMaxSpeed();

	/**
	@brief Gets the strength of the character
	@return The strength of the character
	*/
	float getStrength();

	/**
	@brief Gets the maximum health of the character
	@return The maximum health of the character
	*/
	float getMaxHealth();

protected:
	///A pointer to the spritesheet.
	Texture* spritesheet;

	///The ID of the TileType.
	std::string ID;

	///The dimensions of the sprite in the file.
	Vec2 spriteDimensions;

	///The name of the character
	std::string characterName;

	///The weight of the character
	float weight;

	///The speed of the character
	float speed;

	///The maximum speed this character can move by
	float maxSpeed;

	///The strength of the character
	float strength;

	///The number of hitpoints this character starts off with
	float maxHealth;
};

