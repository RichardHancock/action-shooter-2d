#include <vector>

#include "Particle.h"

#pragma once

/**
@brief An interface to create, manage and destroy particles for one emitter
*/
class ParticleSystem
{
public:
	/**
	 @brief Creates a Particle System.
	
	 @param emitterPos			 Position of the emitter.
	 @param [in,out] texture	 Particle Texture.
	 @param particlesPerCallRate How many particles are created each request.
	 @param direction			 Direction to fire particles.
	 @param min					 Minimum Colour Values for use in random colour generation.
	 @param max					 Maximum Colour Values for use in random colour generation.
	 */
	ParticleSystem(Vec2 emitterPos, Texture* texture, int particlesPerCallRate, 
		Vec2 direction, SDL_Colour min, SDL_Colour max);

	/**
	 @brief Creates a Particle System.
	
	 @param emitterPos			 Position of the emitter.
	 @param [in,out] texture	 Particle Texture.
	 @param particlesPerCallRate How many particles are created each request.
	 @param min					 Minimum Colour Values for use in random colour generation.
	 @param max					 Maximum Colour Values for use in random colour generation.
	 */
	ParticleSystem(Vec2 emitterPos, Texture* texture, int particlesPerCallRate, 
		SDL_Colour min, SDL_Colour max);
	
	/// Clears vectors the particle system created
	~ParticleSystem();

	/**
	 @brief Update all particles in the system
	 
	 Deletes expired particles, and runs update on all particles.
	
	 @param dt Time since last frame.
	 */
	void update(float dt);

	/**
	 @brief Gets emitter position.
	
	 @return The emitter position.
	 */
	Vec2 getEmitterPos() { return emitterPos; }

	/**
	 @brief Changes Emitter position.
	
	 @param newPos New Position.
	 */
	void setEmitterPos(Vec2 newPos);

	/**
	@brief Generate some new particles in the system

	Amount is dictated by the "particlesPerTickRate" passed in through the constructor
	*/
	void generateNewParticles();

	/**
	 @brief Gets particles per call rate.
	
	 @return The particles per call rate.
	 */
	int getParticlesPerCallRate() { return particlesPerCallRate; }

	/**
	 @brief Sets particles per call rate.
	
	 @param newRate The new rate.
	 */
	void setParticlesPerCallRate(int newRate);

	/**
	 @brief Gets the speed of the particles.
	
	 @return The speed.
	 */
	float getSpeed() { return speed; }

	/**
	 @brief Sets the speed of the particles.
	
	 @param newSpeed The new speed.
	 */
	void setSpeed(float newSpeed);

	/**
	 @brief Draws all particles.
	
	 @param [in,out] platform If non-null, the platform.
	 */
	void render(Platform* platform);

private:

	/// Position of the Particle Emitter
	Vec2 emitterPos;
	/// Vector containing all the particles in the system
	std::vector<Particle> particles;
	/// Particle Textures
	Texture* texture;
	/// How many particles will be created every request
	int particlesPerCallRate;
	/// Direction to emit particles
	Vec2 direction;
	///Should the direction Vec2 be used
	bool useDirection;
	///Minimum Colour Values for use in random colour generation
	SDL_Colour min;
	///Maximum Colour Values for use in random colour generation
	SDL_Colour max;
	///The speed of the particles.
	float speed;

};
