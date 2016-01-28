#include "CreatureType.h"

#include "../../Utility.h"

CreatureType::CreatureType(Texture* spritesheet, std::string ID, std::string creatureName, Vec2 spriteDimensions,
	float weight, float speed, float maxSpeed, float strength, float maxHealth) :
	spritesheet(spritesheet), ID(ID), creatureName(creatureName), spriteDimensions(spriteDimensions),
	weight(weight), speed(speed), maxSpeed(maxSpeed), strength(strength), maxHealth(maxHealth)
{
}

CreatureType::~CreatureType()
{

}

void CreatureType::render(SDL_Renderer *renderer, Vec2 pos, Vec2 dimensions, int state, int frame)
{
	spritesheet->pushSpriteToScreen(renderer, pos, dimensions, Vec2(frame * spriteDimensions.x, state * spriteDimensions.y), spriteDimensions);
}

Texture* CreatureType::getTexture()
{
	return spritesheet;
}

std::string CreatureType::getID()
{
	return ID;
}


Vec2 CreatureType::getSpriteDimensions()
{
	return spriteDimensions;
}

float CreatureType::getWeight()
{
	return weight;
}

float CreatureType::getSpeed()
{
	return speed;
}

float CreatureType::getMaxSpeed()
{
	return maxSpeed;
}

float CreatureType::getStrength()
{
	return strength;
}

float CreatureType::getMaxHealth()
{
	return maxHealth;
}

