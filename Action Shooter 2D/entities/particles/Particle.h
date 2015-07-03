#include "../EntityWithMotion.h"
#include "../../Platform.h"

#pragma once

/**
@brief A particle only created by a ParticleSystem
*/
class Particle : public EntityWithMotion
{
public:
	/**
	 @brief Create a Particle.
	
	 @param [in,out] texture Pointer to texture for the particle to display.
	 @param pos				 Particles position.
	 @param colour			 Colour/Tint to apply.
	 @param lifespan		 Lifespan of the particle (Almost in seconds)
	 */
	Particle(Texture* texture, Vec2 pos, SDL_Colour colour, float lifespan);
	
	/**
	 @brief Updates a Particle
	 
	 Applies velocity and lowers it's lifespan.
	
	 @param dt Time since last frame.
	 */
	void update(float dt);

	/**
	 @brief Draw the particle.
	
	 @param [in,out] platform If non-null, the platform.
	 */
	void render(Platform* platform);

	/**
	@brief Checks if the lifespan of the particle has run out
	
	@return True if expired
	*/
	bool hasExpired();

private:
	/// Tint to apply to the texture
	SDL_Colour colour;

	/// How long the particle will exist (Almost in seconds)
	float lifespan;
};