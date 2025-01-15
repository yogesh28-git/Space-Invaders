
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Header/GameService.h"

/*
class Player
{
private:
    
    int player_score = 0;
    int health = 3;
    int movement_speed = 200;
    sf::Vector2f position = sf::Vector2f(100, 100);

public:

    sf::Texture player_texture;
    sf::Sprite  player_sprite;

    void takeDamage();

    void move(float horizontal_movement)
    {
        position.x += horizontal_movement;
    }
    void shootBullets();

    sf::Vector2f getPosition()
    {
        return position;
    }

    int getMovementSpeed()
    {
        return movement_speed;
    }
};
*/

int main()
{
    GameService* game_service = new GameService();

    game_service->ignite();

    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    }

    return 0;

    /*
    sf::VideoMode videoMode = sf::VideoMode(800, 800);
    sf::RenderWindow window(videoMode, "Resizable Window", sf::Style::Resize | sf::Style::Close);

    sf::Clock clock;

    // PLAYER CREATION
    Player player;

    player.player_texture.loadFromFile("assets/textures/player_ship.png");
    player.player_sprite.setTexture(player.player_texture);

    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
        }

        // Calculate delta time
        float deltaTime = clock.restart().asSeconds();


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.move(-player.getMovementSpeed() * deltaTime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.move(player.getMovementSpeed() * deltaTime);

        //Render
        window.clear();

        player.player_sprite.setPosition(player.getPosition());
        window.draw(player.player_sprite);

        window.display();
    }
    */

    
}