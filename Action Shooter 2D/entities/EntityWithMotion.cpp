#include "EntityWithMotion.h"

EntityWithMotion::EntityWithMotion(Vec2 pos)
	: Entity(pos), velocity(0)
{

}

EntityWithMotion::EntityWithMotion(Vec2 pos, Vec2 dimensions)
	: Entity(pos, dimensions), velocity(0)
{

}

EntityWithMotion::~EntityWithMotion()
{

}