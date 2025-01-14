
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:
    
    int player_score = 0;
    int health = 3;
    int movement_speed = 5;
    sf::Vector2f position = sf::Vector2f(200, 100);

public:

    sf::Texture player_texture;
    sf::Sprite  player_sprite;

    void takeDamage();
    void move();
    void shootBullets();
};

int main()
{
    sf::VideoMode videoMode = sf::VideoMode(800, 800);
    sf::RenderWindow window(videoMode, "Resizable Window", sf::Style::Resize | sf::Style::Close);

    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                window.close();


            window.clear(sf::Color::Blue);
            window.display();
        }
    }
    return 0;
}