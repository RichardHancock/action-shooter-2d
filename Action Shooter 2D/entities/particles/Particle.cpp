#include "Particle.h"

Particle::Particle(Texture* texture, Vec2 pos, float maxRotationSpeed, Colour colour, float lifespan)
	: EntityWithMotion(texture, pos, maxRotationSpeed), colour(colour), lifespan(lifespan)
{
	
}

void Particle::update(float dt)
{
	//Apply velocity
	pos += ((velocity * 10) * dt);

	//Lower lifespan
	lifespan -= dt;
}

void Particle::render()
{
	sprite->setColourTint(colour);

	sprite->draw(pos, rotation);
}

bool Particle::hasExpired()
{
	if(lifespan <= 0.00f)
	{
		return true;
	}
	else
	{
		return false;
	}
}