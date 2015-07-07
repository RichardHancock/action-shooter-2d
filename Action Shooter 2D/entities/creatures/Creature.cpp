#include "Creature.h"

Creature::Creature(Texture* texture, Vec2 pos, CreatureType *creatureType) : Entity(texture, pos)
{
}

Creature::Creature(Texture* texture, Vec2 pos, Vec2 dimensions, CreatureType *creatureType) : Entity(texture, pos, dimensions)
{
}	

Creature::Creature(Texture* texture, Vec2 pos, Vec2 dimensions, Vec2 spritePos, Vec2 spriteDimensions, CreatureType *creatureType) : Entity(texture, pos, dimensions, spritePos, spriteDimensions)
{
}

Creature::~Creature()
{
}

void Creature::update(float dt)
{

}

void Creature::render(SDL_Renderer* renderer)
{

}