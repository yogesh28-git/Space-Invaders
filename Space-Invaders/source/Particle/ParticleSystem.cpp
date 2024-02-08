#include "../../header/Particle/ParticleSystem.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Particle/ParticleService.h"

namespace Particle
{
	using namespace Global;

	ParticleSystem::ParticleSystem(ParticleSystemConfig config) { particle_system_config = config; }

	ParticleSystem::~ParticleSystem() { }

	void ParticleSystem::initialize(sf::Vector2f position)
	{
		particles_position = position;
		current_frame = 0;
		frame_time = sf::seconds(particle_system_config.frame_duration);

		initializeParticlesSprite();
	}

	void ParticleSystem::initializeParticlesSprite()
	{
		if (particles_texture.loadFromFile(particle_system_config.particles_texture_path))
		{
			particles_sprite.setPosition(particles_position);
			particles_sprite.setTexture(particles_texture);
			particles_sprite.setTextureRect(sf::IntRect(0, 0, particle_system_config.tile_width, particle_system_config.tile_height));

			scaleParticlesSprite();
		}
	}

	void ParticleSystem::scaleParticlesSprite()
	{
		particles_sprite.setScale(
			static_cast<float>(particle_system_config.particles_sprite_width) / particle_system_config.tile_width,
			static_cast<float>(particle_system_config.particles_sprite_height) / particle_system_config.tile_height
		);
	}

	void ParticleSystem::update()
	{
		if (clock.getElapsedTime() >= frame_time)
		{
			if (current_frame + 1 >= particle_system_config.number_of_animation_frames) 
				destroy();

			current_frame = (current_frame + 1) % particle_system_config.number_of_animation_frames;
			clock.restart();

			particles_sprite.setTextureRect(sf::IntRect(
				current_frame * particle_system_config.tile_width, 
				0, 
				particle_system_config.tile_width,
				particle_system_config.tile_height));
		}
	}

	void ParticleSystem::render()
	{
		ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->draw(particles_sprite);
	}

	void ParticleSystem::destroy()
	{
		ServiceLocator::getInstance()->getParticleService()->destroyParticleSystem(this);
	}
}