
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //sf::RenderWindow window(sf::VideoMode(800,800), "SFML Works !!");
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Resizable Window", sf::Style::Resize | sf::Style::Close);
    //sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Fullscreen Window", sf::Style::Fullscreen | sf::Style::Close);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    window.setPosition(sf::Vector2i(0, 0));
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    
    return 0;
}