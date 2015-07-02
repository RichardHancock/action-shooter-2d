#include "Entity.h"

#pragma once

class EntityWithMotion : public Entity
{
public:

	EntityWithMotion(Texture* texture, Vec2 pos);

	EntityWithMotion(Texture* Texture, Vec2 pos, Vec2 dimensions);

	~EntityWithMotion();

	Vec2 getVelocity() { return velocity; }

	void setVelocity(Vec2 newVelocity) { velocity = newVelocity; }

	virtual void update(float dt) = 0;

protected:
	
	Vec2 velocity;
};