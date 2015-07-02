#include "EntityWithMotion.h"

EntityWithMotion::EntityWithMotion(Texture* texture, Vec2 pos)
	: Entity(texture, pos), velocity(0)
{

}

EntityWithMotion::EntityWithMotion(Texture* texture, Vec2 pos, Vec2 dimensions)
	: Entity(texture, pos, dimensions), velocity(0)
{

}

EntityWithMotion::~EntityWithMotion()
{

}