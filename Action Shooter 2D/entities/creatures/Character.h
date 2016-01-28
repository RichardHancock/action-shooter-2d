#pragma once

#include "../Entity.h"
#include "CharacterType.h"


class Character : public Entity
{
public:

	/**
	@brief Create the character using the size of the Texture as the size of the character.
	@param texture A pointer to the Texture.
	@param pos The position of the character.
	*/
	Character(Texture* texture, Vec2 pos, CharacterType *characterType);

	/**
	@brief Create the character.
	@param texture A pointer to the Texture.
	@param pos The position of the character.
	@param dimensions The dimensions of the character.
	*/
	Character(Texture* texture, Vec2 pos, Vec2 dimensions, CharacterType *characterType);

	/**
	@brief Create the character with a sprite from a spritesheet.
	@param texture A pointer to the Texture.
	@param pos The position of the character.
	@param dimensions The dimensions of the character.
	@param spriteDimensions The dimensions of the sprite in the spritesheet.
	*/
	
	Character(Texture* texture, Vec2 pos, Vec2 dimensions, Vec2 spriteDimensions, CharacterType *characterType);

	~Character();

	/**
	@brief Update the Character.
	@param dt The delta time.
	*/
	virtual void update(float dt);


	/**
	@brief Render the Character.
	@param renderer A pointer to the renderer.
	*/
	virtual void render(SDL_Renderer* renderer);

	/**
	@brief Set the character type

	*/
	void setCharacterType(CharacterType* charType);

	CharacterType* getCharacterType();

private:
	///Reference to CharacterType
	CharacterType *characterType;
	

};