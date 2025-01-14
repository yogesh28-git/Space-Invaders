
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //sf::RenderWindow window(sf::VideoMode(800,800), "SFML Works !!");
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Resizable Window", sf::Style::Resize | sf::Style::Close);
    //sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Fullscreen Window", sf::Style::Fullscreen | sf::Style::Close);

    // Green Circle
    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Green);

    // Red Square
    sf::RectangleShape square(sf::Vector2f(200, 200));
    square.setFillColor(sf::Color::Red);
    square.setPosition(0, 250);

    // Blue Triangle
    sf::ConvexShape triangle(3);
    triangle.setPoint(0, sf::Vector2f(100, 100));
    triangle.setPoint(1, sf::Vector2f(0, 300));
    triangle.setPoint(2, sf::Vector2f(200, 300));
    triangle.setFillColor(sf::Color::Blue);
    triangle.setPosition(0, 400);

    
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(circle);
        window.draw(square);
        window.draw(triangle);
        window.display();
    }
    
    return 0;
}