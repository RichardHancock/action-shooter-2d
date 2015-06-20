#include "Vec2.h"

#pragma once

class Entity
{
public:
	/**
	@brief Create the Entity.

	@param p - Vec2 position
	*/
	Entity(Vec2 p);
	/**
	@brief Create the Entity.

	@param p - Vec2 position
	@param d - Vec2 dimensions
	*/
	Entity(Vec2 p, Vec2 d);

	virtual ~Entity() {}

	/**
	@brief Set the entity's position

	@param p - Vec2 position
	*/
	void setPosition(Vec2 p);

	/**
	@brief Get the entity's position

	@return Entity's position
	*/
	Vec2 getPosition();

	/**
	@brief Set the entity's dimensions

	@param d - Vec2 dimensions
	*/
	void setDimensions(Vec2 d);

	/**
	@brief Get the entity's dimensions

	@return Entity's dimensions
	*/
	Vec2 getDimensions();



	/**
	@brief Update any internal values.

	@param dt - delta time.
	*/
	virtual void update(float dt) = 0;

	/**
	@brief Render any sprites relevant to the entity
	*/
	virtual void render() = 0;

protected:
	/// The position of this entity - x, y
	Vec2 pos;

	/// The dimensions of this entity - width, height
	Vec2 dimen;
	
};