#pragma once
#include <SFML/Graphics.hpp>

namespace Particle
{
	enum class ParticlesType
	{
		EXPLOSION,
	};

    class ParticleSystem
    {
    private:
        const float particles_sprite_width = 70.f;
        const float particles_sprite_height = 80.f;

        const float tile_width = 14.28f;
        const float tile_height = 20.0f;

        const int number_of_animation_frames = 7;
        const float frame_duration = 0.03f;

        sf::Vector2f particles_position;
        ParticlesType particles_type;

        sf::Texture particles_texture;
        sf::Sprite particles_sprite;
        sf::Clock clock;

        int current_frame;
        sf::Time frame_time;

        void initializeParticlesSprite();
        void scaleParticlesSprite();
        sf::String getTexturePath(ParticlesType type);
      
    public:
        ParticleSystem(ParticlesType type);
        ~ParticleSystem();

        void initialize(sf::Vector2f position);
        void update();
        void render();

        void destroy();
    };
}