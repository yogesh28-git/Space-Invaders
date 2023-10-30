#pragma once
#include "../../header/Gameplay/Interface/ITest.h"
#include <SFML/Graphics.hpp>

namespace Gameplay
{
    class AnimationTest : public Interface::ITest
    {
    private:
        const sf::String texture_path = "assets/textures/circle_animation.png";

        const float tile_width = 16;
        const float tile_height = 16;

        const int number_of_animation_frames = 12;
        const float frame_duration = 0.2f;
        const float sprite_scale = 5.f;

        const sf::Vector2f sprite_position = sf::Vector2f(940.f, 490.f);

        sf::Texture texture;
        sf::Sprite sprite;
        sf::Clock clock;

        int currentFrame;
        sf::Time frameTime;

    public:
        void initialize() override;
        void update() override;
        void render() override;
    };
}