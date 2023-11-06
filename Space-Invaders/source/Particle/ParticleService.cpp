#include "../../header/Particle/ParticleService.h"

namespace Particle
{
	ParticleService::ParticleService() { }

	ParticleService::~ParticleService() { destroy(); }

	void ParticleService::initialize() { }

	void ParticleService::update()
	{
		for (int i = 0; i < particle_system_list.size(); i++) particle_system_list[i]->update();
		destroyFlaggedParticleSystem();
	}

	void ParticleService::render()
	{
		for (int i = 0; i < particle_system_list.size(); i++) particle_system_list[i]->render();
	}

	void ParticleService::spawnParticleSystem(sf::Vector2f position, Particle::ParticlesType partcles_type)
	{
		ParticleSystem* particle_system = new ParticleSystem(partcles_type);
		particle_system->initialize(position);
		particle_system_list.push_back(particle_system);
	}

	void ParticleService::destroyParticleSystem(ParticleSystem* particle_system)
	{
		flagged_particle_system_list.push_back(particle_system);
		particle_system_list.erase(std::remove(particle_system_list.begin(), particle_system_list.end(), particle_system), particle_system_list.end());
	}

	void ParticleService::destroyFlaggedParticleSystem()
	{
		for (int i = 0; i < flagged_particle_system_list.size(); i++) delete (flagged_particle_system_list[i]);
		flagged_particle_system_list.clear();
	}

	void ParticleService::reset() { destroy(); }

	void ParticleService::destroy()
	{
		for (int i = 0; i < particle_system_list.size(); i++) delete (particle_system_list[i]);
		particle_system_list.clear();
	}
}