#pragma once
#include "../../header/Gameplay/Interface/ITest.h"
#include <SFML/Graphics.hpp>

namespace Gameplay
{
    class SFMLTest : public Interface::ITest
    {
    private:
        const float rectangle_width = 200.f;
        const float rectangle_height = 200.f;

        const sf::Color rectangle_color = sf::Color::Red;
        const sf::Vector2f rectangle_position = sf::Vector2f(860.f, 460.f);

        sf::RectangleShape rectangle_shape;

    public:
        void initialize() override;
        void update() override;
        void render() override;
    };
}