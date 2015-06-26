#include "Particle.h"

Particle::Particle(Texture* texture, Vec2 pos, SDL_Colour colour, float lifespan)
	: EntityWithMotion(pos), colour(colour), lifespan(lifespan)
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
	//sprite->setColourTint(colour);

	//sprite->draw(pos, rotation);
}

bool Particle::hasExpired()
{
	return lifespan <= 0.00f;
}