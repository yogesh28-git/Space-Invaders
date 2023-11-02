#pragma once
#include <SFML/Graphics.hpp>

class SFMLTest
{
private:
    const float rectangle_width = 200.f;
    const float rectangle_height = 200.f;

    const sf::Color rectangle_color = sf::Color::Red;
    const sf::Vector2f rectangle_position = sf::Vector2f(860.f, 460.f);

    sf::RectangleShape rectangle_shape;

public:
    void initialize();
    void update();
    void render();
};