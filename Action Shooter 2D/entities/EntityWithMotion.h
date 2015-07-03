#include "Entity.h"

#pragma once

/** @brief An entity that moves (has a velocity). */
class EntityWithMotion : public Entity
{
public:

	/**
	 @brief Create a EntityWithMotion.
	
	 @param [in,out] texture The texture the Entity will use.
	 @param pos				 The position of the Entity.
	 */
	EntityWithMotion(Texture* texture, Vec2 pos);

	/**
	 @brief Create a EntityWithMotion.
	
	 @param [in,out] Texture The texture the Entity will use.
	 @param pos				 The position of the Entity.
	 @param dimensions		 The dimensions of the Entity.
	 */
	EntityWithMotion(Texture* Texture, Vec2 pos, Vec2 dimensions);

	~EntityWithMotion();

	/**
	 @brief Gets the Entity's velocity.
	
	 @return The velocity.
	 */
	Vec2 getVelocity() { return velocity; }

	/**
	 @brief Sets the Entity's velocity.
	
	 @param newVelocity The new velocity.
	 */
	void setVelocity(Vec2 newVelocity) { velocity = newVelocity; }

	/**
	 @brief Updates the Entity.
	
	 @param dt The deltatime.
	 */
	virtual void update(float dt) = 0;

protected:
	/** @brief The Entity's velocity. */
	Vec2 velocity;
};