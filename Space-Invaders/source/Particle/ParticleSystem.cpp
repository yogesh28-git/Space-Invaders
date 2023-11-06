#include "../../header/Particle/ParticleSystem.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Particle/ParticleService.h"

namespace Particle
{
	using namespace Global;

	ParticleSystem::ParticleSystem(ParticlesType type) { particles_type = type;  }

	ParticleSystem::~ParticleSystem() { }

	void ParticleSystem::initialize(sf::Vector2f position)
	{
		particles_position = position;
		current_frame = 0;
		frame_time = sf::seconds(frame_duration);

		initializeParticlesSprite();
	}

	void ParticleSystem::initializeParticlesSprite()
	{
		if (particles_texture.loadFromFile(getTexturePath(particles_type)))
		{
			particles_sprite.setPosition(particles_position);
			particles_sprite.setTexture(particles_texture);
			particles_sprite.setTextureRect(sf::IntRect(0, 0, tile_width, tile_height));

			scaleParticlesSprite();
		}
	}

	void ParticleSystem::scaleParticlesSprite()
	{
		particles_sprite.setScale(
			static_cast<float>(particles_sprite_width) / tile_width,
			static_cast<float>(particles_sprite_height) / tile_height
		);
	}

	sf::String ParticleSystem::getTexturePath(ParticlesType type)
	{
		switch (type)
		{
		case Particle::ParticlesType::EXPLOSION:
			return Config::explosion_texture_path;
		}
	}

	void ParticleSystem::update()
	{
		if (clock.getElapsedTime() >= frame_time)
		{
			if (current_frame + 1 >= number_of_animation_frames) destroy();

			current_frame = (current_frame + 1) % number_of_animation_frames;
			particles_sprite.setTextureRect(sf::IntRect(current_frame * tile_width, 0, tile_width, tile_height));
			clock.restart();
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