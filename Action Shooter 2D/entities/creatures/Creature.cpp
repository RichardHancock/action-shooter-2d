#include "Creature.h"

Creature::Creature(Texture* texture, Vec2 pos, CreatureType *creatureType) : Entity(texture, pos), creatureType(creatureType)
{
	frame = 0;
	state = 0;
}

Creature::Creature(Texture* texture, Vec2 pos, Vec2 dimensions, CreatureType *creatureType) : Entity(texture, pos, dimensions), creatureType(creatureType)
{
	frame = 0;
	state = 0;
}	

Creature::Creature(Texture* texture, Vec2 pos, Vec2 dimensions, Vec2 spriteDimensions, CreatureType *creatureType) : Entity(texture, pos, dimensions, Vec2(0, 0), spriteDimensions), creatureType(creatureType)
{
	frame = 0;
	state = 0;
}

Creature::~Creature()
{
}

void Creature::update(float dt)
{

}

void Creature::render(SDL_Renderer* renderer)
{
	//If the Tile does not have a blank ID then render to the Tile
	if (creatureType->getID() != "XX")
	{
		creatureType->render(renderer, pos, dimensions, state, frame);
	}
}