#include <vector>

#include "../Vec2.h"
#include "../Texture.h"
#include "Particle.h"

#pragma once

//Self Reference: This code was used in a previous assignment with moderate changes

/**
@brief An interface to create, manage and destroy particles for one emitter
*/
class ParticleSystem
{
public:
	/**
	@brief Creates a Particle System
	
	@param Vec2 - Position of the emitter
	@param std::vector<Texture*> - Array of texture*
	@param int - How many particles are created each request
	@param Vec2 - Direction to generate particles
	@param Colour - Minimum Colour Values for use in random colour generation
	@param Colour - Maximum Colour Values for use in random colour generation
	*/
	ParticleSystem(Vec2 emitterPos, std::vector<Texture*> textures, int particlesPerCallRate, Vec2 direction
		,Colour min, Colour max);

	/**
	@brief Creates a Particle System

	@param Vec2 - Position of the emitter
	@param texture - texture
	@param int - How many particles are created each request
	@param Colour - Minimum Colour Values for use in random colour generation
	@param Colour - Maximum Colour Values for use in random colour generation
	*/
	ParticleSystem(Vec2 emitterPos, Texture* texture, int particlesPerCallRate, Colour min, Colour max);
	
	/// Clears vectors the particle system created
	~ParticleSystem();

	/**
	@brief Update all particles in the system
	
	Deletes expired particles, and runs update on all particles.
	@param float - Time since last frame
	*/
	void update(float dt);

	/**
	 @brief Gets emitter position.
	
	 @return The emitter position.
	 */
	Vec2 getEmitterPos() { return emitterPos; }

	/**
	@brief Changes Emitter position
	@param Vec2 - New Position
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
	@brief Draws all particles
	*/
	void render();
private:
	/// Position of the Particle Emitter
	Vec2 emitterPos;
	/// Vector containing all the particles in the system
	std::vector<Particle> particles;
	/// Contains all available textures for the particles to use
	std::vector<Texture*> textures;
	/// How many particles will be created every request
	int particlesPerCallRate;
	/// Direction to emit particles
	Vec2 direction;
	///Minimum Colour Values for use in random colour generation
	Colour min;
	///Maximum Colour Values for use in random colour generation
	Colour max;
	/** @brief The speed of the particles. */
	float speed;

	/// If no direction is wanted this tell the generator to use all directions
	const int NO_DIRECTION = -454;

	/** @brief The maximum particles per call. */
	const int MAX_PARTICLES_PER_CALL = 100;

	/** @brief The maximum speed of the particles. */
	const int MAX_SPEED = 20;

};
