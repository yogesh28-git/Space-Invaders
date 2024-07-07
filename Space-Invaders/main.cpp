#include <SFML/Graphics.hpp>

int main()
{
    sf::VideoMode videoMode(800, 600);
    sf::RenderWindow window(videoMode, "Space-Invaders");
    window.setFramerateLimit(60);

    sf::RectangleShape square(sf::Vector2f(50, 50));
    square.setPosition(300, 300);
    square.setFillColor(sf::Color::Red);

    sf::CircleShape circle(50);
    circle.setPosition(500, 400);
    circle.setFillColor(sf::Color::Green);

    sf::ConvexShape triangle(3);
    triangle.setPoint(0, sf::Vector2f(0,0));
    triangle.setPoint(1, sf::Vector2f(100, 0));
    triangle.setPoint(2, sf::Vector2f(50, 100));
    triangle.setFillColor(sf::Color::Blue);
    triangle.setPosition(200, 200);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(circle);
        window.draw(square);
        window.draw(triangle);

        window.display();
    }

    return 0;
}