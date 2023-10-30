#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
    class PlayerView;
    class PlayerModel;

    enum class PlayerState;

    class PlayerController
    {
    private:
        const float player_movement_speed = 350.0f;
        const sf::Vector2f left_most_position = sf::Vector2f(50.f, 950.f);
        const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 950.f);

        PlayerView* player_view;
        PlayerModel* player_model;

        void processPlayerInput();
        void moveLeft();
        void moveRight();

    public:
        PlayerController();
        ~PlayerController();

        void initialize();
        void update();
        void render();

        sf::Vector2f getPlayerPosition();
        int getPlayerScore();
        PlayerState getPlayerState();
    };
}