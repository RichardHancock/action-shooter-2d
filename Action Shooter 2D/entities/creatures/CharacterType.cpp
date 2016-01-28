#pragma once
#include "CharacterType.h"

#include "../../Utility.h"

CharacterType::CharacterType(Texture* spritesheet, std::string ID, std::string characterName, Vec2 spriteDimensions,
	float weight, float speed, float maxSpeed, float strength, float maxHealth) :
	spritesheet(spritesheet), ID(ID), characterName(characterName), spriteDimensions(spriteDimensions),
	weight(weight), speed(speed), maxSpeed(maxSpeed), strength(strength), maxHealth(maxHealth)
{
}

CharacterType::~CharacterType()
{

}

void CharacterType::render(SDL_Renderer *renderer, Vec2 pos, Vec2 dimensions, int state, int frame)
{
	spritesheet->pushSpriteToScreen(renderer, pos, dimensions, Vec2(frame * spriteDimensions.x, state * spriteDimensions.y), spriteDimensions);
}

Texture* CharacterType::getTexture()
{
	return spritesheet;
}

std::string CharacterType::getID()
{
	return ID;
}


Vec2 CharacterType::getSpriteDimensions()
{
	return spriteDimensions;
}

float CharacterType::getWeight()
{
	return weight;
}

float CharacterType::getSpeed()
{
	return speed;
}

float CharacterType::getMaxSpeed()
{
	return maxSpeed;
}

float CharacterType::getStrength()
{
	return strength;
}

float CharacterType::getMaxHealth()
{
	return maxHealth;
}

