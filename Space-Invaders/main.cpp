#include <SFML/Graphics.hpp>


class Player
{

private:
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    int health = 3;
    int movementSpeed = 10;
    sf::Vector2f position{ 400,500 };

public:
    void takeDamage()
    {

    }
    void move()
    {
        
    }
    void shootBullets()
    {

    }
};


int main()
{
    sf::VideoMode videoMode(800, 600);
    sf::RenderWindow window(videoMode, "Space-Invaders");
    window.setFramerateLimit(60);
    sf::Vector2f v1(16.5f, 24.f);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        window.display();
    }

    return 0;
}