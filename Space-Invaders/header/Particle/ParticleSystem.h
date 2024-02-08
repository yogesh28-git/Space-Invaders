#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/Particle/ParticleSystemConfig.h"

namespace Particle
{
    class ParticleSystem
    {
    private:    
        ParticleSystemConfig particle_system_config;
        
        sf::Vector2f particles_position;

        sf::Texture particles_texture;
        sf::Sprite particles_sprite;
        sf::Clock clock;

        int current_frame;
        sf::Time frame_time;

        void initializeParticlesSprite();
        void scaleParticlesSprite();
      
    public:
        ParticleSystem(ParticleSystemConfig config);
        ~ParticleSystem();

        void initialize(sf::Vector2f position);
        void update();
        void render();

        void destroy();
    };
}