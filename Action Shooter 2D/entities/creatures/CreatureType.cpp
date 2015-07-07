#include "CreatureType.h"

CreatureType::CreatureType(Texture* spritesheet, std::string creatureName, Vec2 spriteDimensions,
	float weight, float speed, float maxSpeed, float strength, float maxHealth) :
	spritesheet(spritesheet), creatureName(creatureName), spriteDimensions(spriteDimensions),
	weight(weight), speed(speed), maxSpeed(maxSpeed), strength(strength), maxHealth(maxHealth)
{
}

CreatureType::~CreatureType()
{

}

void CreatureType::render(SDL_Renderer *renderer, Vec2 pos, int state, int frame)
{
	spritesheet->pushSpriteToScreen(renderer, pos, Vec2(state, frame), spriteDimensions);
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

