#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../header/Particle/ParticleSystem.h"

namespace Particle
{
	class ParticleService
	{
	private:

		std::vector<ParticleSystem*> particle_system_list;
		std::vector<ParticleSystem*> flagged_particle_system_list;

		void destroyFlaggedParticleSystem();
		void destroy();

	public:
		ParticleService();
		virtual ~ParticleService();

		void initialize();
		void update();
		void render();

		void reset();

		void spawnParticleSystem(sf::Vector2f position, Particle::ParticlesType partcles_type);
		void destroyParticleSystem(ParticleSystem* particle_system);
	};
}