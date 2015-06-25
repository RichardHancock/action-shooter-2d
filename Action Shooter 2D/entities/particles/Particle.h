#include "../entities/EntityWithMotion.h"
#include "../Utility.h"

#pragma once

//Self Reference: This code was used in a previous assignment.

/**
@brief A particle only created by a ParticleSystem
*/
class Particle : public EntityWithMotion
{
public:
	/**
	@brief Create a Particle
	
	@param Texture* - Pointer to texture for the particle to display
	@param Vec2 - Particles position
	@param float - The maximum rotation speed
	@param Colour - Colour/Tint to apply
	@param float - Lifespan of the particle (Almost in seconds)
	*/
	Particle(Texture*,Vec2,float,Colour,float);
	
	/**
	@brief Updates a Particle
	
	Applies velocity and lowers it's lifespan
	@param float - Time since last frame
	*/
	void update(float);

	/// Draw the particle
	void render();

	/**
	@brief Checks if the lifespan of the particle has run out
	
	@return bool - True if expired
	*/
	bool hasExpired();

private:
	/// Tint to apply to the texture
	Colour colour;
	/// How long the particle will exist (Almost in seconds)
	float lifespan;
};