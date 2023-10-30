#pragma once
#include "../../header/Gameplay/Interface/ITest.h"
#include <SFML/Graphics.hpp>

namespace Gameplay
{
    class CollisionDetectionTest : public Interface::ITest
    {
    private:
        const sf::Color rectangle_one_color = sf::Color::Red;
        const sf::Color rectangle_two_color = sf::Color::Green;
        const sf::Color rectangle_intersection_color = sf::Color::Yellow;

        const sf::Vector2f rectangle_one_position = sf::Vector2f(600.f, 400.f);
        const sf::Vector2f rectangle_two_position = sf::Vector2f(850.f, 550.f);
        const sf::Vector2f rectangle_intersection_position = sf::Vector2f(900.f, 450.f);

        const sf::Vector2f rectangle_size = sf::Vector2f(150.f, 150.f);

        sf::RectangleShape rectangle_shape_one;
        sf::RectangleShape rectangle_shape_two;

        void updateRectanglePosition();
        void updateRectangleColor();

    public:
        void initialize() override;
        void update() override;
        void render() override;
    };
}