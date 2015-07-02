#include "ParticleSystem.h"
#include "../../Utility.h"

ParticleSystem::ParticleSystem(Vec2 emitterPos, Texture* texture, int particlesPerCallRate, 
	Vec2 direction, SDL_Colour min, SDL_Colour max)
	: emitterPos(emitterPos), texture(texture), particlesPerCallRate(particlesPerCallRate), direction(direction), min(min), max(max)
{
	speed = 1.0f;
	useDirection = true;
}

ParticleSystem::ParticleSystem(Vec2 emitterPos, Texture* texture, int particlesPerCallRate, 
	SDL_Colour min, SDL_Colour max)
	: emitterPos(emitterPos), texture(texture), particlesPerCallRate(particlesPerCallRate), min(min), max(max)
{
	speed = 1.0f;
	direction = Vec2(0);
	useDirection = false;
}

ParticleSystem::~ParticleSystem()
{
	particles.clear();
	
	delete texture;
}

void ParticleSystem::update(float dt)
{
	std::vector<int> particlesToErase;
	
	for (unsigned int i = 0; i < particles.size(); i++)
	{
		particles[i].update(dt);

		// Check if the particle has exceeded its lifespan
		if (particles[i].hasExpired())
		{
			// Add the particle to a vector as deleting it in this loop would get messy.
			particlesToErase.push_back(i);
		}
	}

	// Now delete the destroyed particles
	for (unsigned int i = 0; i < particlesToErase.size(); i++)
	{
		particles.erase(particles.begin() + (particlesToErase[i] - i));
	}

	particlesToErase.clear();
	//Maybe put generateNewParticles here but might be better to have for external calls only
}

void ParticleSystem::setEmitterPos(Vec2 newPos)
{
	emitterPos = newPos;
}

void ParticleSystem::render(Platform* platform)
{
	for (unsigned int i = 0; i < particles.size(); i++)
	{
		particles[i].render(platform);
	}
}

void ParticleSystem::generateNewParticles()
{
	for (int i = 0; i < particlesPerCallRate; i++)
	{
		SDL_Colour colour;
		colour.r = Utility::randomInt(min.r, max.r);
		colour.g = Utility::randomInt(min.g, max.g);
		colour.b = Utility::randomInt(min.b, max.b);

		Particle particle(texture, emitterPos, colour, 2);
		
		Vec2 randomVelocity;
		if (!useDirection)
		{
			randomVelocity.x = Utility::randomFloat(-1.0f, 1.0f);
			randomVelocity.y = Utility::randomFloat(-1.0f, 1.0f);
		}
		else
		{
			randomVelocity.x = Utility::randomFloat(direction.x - 2, direction.x + 2);
			randomVelocity.y = Utility::randomFloat(direction.y - 2, direction.y + 2);
		}
	
		particle.setVelocity(randomVelocity * speed);
		particles.push_back(particle);
	}
}

void ParticleSystem::setParticlesPerCallRate(int newRate)
{
	particlesPerCallRate = newRate;
}

void ParticleSystem::setSpeed(float newSpeed)
{
	speed = newSpeed;
}