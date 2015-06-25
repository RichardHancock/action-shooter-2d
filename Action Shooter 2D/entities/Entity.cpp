#include "Entity.h"

Entity::Entity(Vec2 pos)
	: pos(pos)
{
	//pos = p;
	dimen = Vec2(0, 0);
}

Entity::Entity(Vec2 p, Vec2 d)
{
	pos = p;
	dimen = d;
}

void Entity::setPosition(Vec2 p)
{
	pos = p;
}

Vec2 Entity::getPosition()
{
	return pos;
}

void Entity::setDimensions(Vec2 d)
{
	dimen = d;
}

Vec2 Entity::getDimensions()
{
	return dimen;
}

void Entity::render(SDL_Renderer *renderer)
{
	entityImg->pushSpriteToScreen(renderer, pos, Vec2(0), dimen);
}