#include <SFML/Graphics.hpp>


class PlayerShip
{

private:
    int health = 3;
    int movementSpeed = 5;
    sf::Vector2f position{ 400,500 };

public:
    sf::Texture player_texture;
    sf::Sprite player_sprite;
    void takeDamage()
    {

    }
    void move(float xOffset)
    {
        position.x += xOffset;
    }
    void shootBullets()
    {

    }
    sf::Vector2f getPosition()
    {
        return position;
    }
    int getMovementSpeed()
    {
        return movementSpeed;
    }
};


int main()
{
    sf::VideoMode videoMode(800, 600);
    sf::RenderWindow window(videoMode, "Space-Invaders");
    window.setFramerateLimit(60);
    

    //Player
    PlayerShip player;
    if (!player.player_texture.loadFromFile("assets/textures/player_ship.png"))
    {
        printf("Could not load player texture");
        return 0;
    }
    player.player_sprite.setTexture(player.player_texture);


    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
            
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            player.move(-1.0f * player.getMovementSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            player.move(1.0f * player.getMovementSpeed());
        }

        window.clear(sf::Color::Black);

        player.player_sprite.setPosition(player.getPosition());

        window.draw(player.player_sprite);

        window.display();
    }

    return 0;
}