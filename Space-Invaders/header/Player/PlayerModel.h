#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
    enum class PlayerState
    {
        ALIVE,
        DEAD,
    };

    class PlayerModel
    {
    private:
        const sf::Vector2f initial_player_position = sf::Vector2f(950.f, 950.f);

        sf::Vector2f player_position;

        PlayerState player_state;
        int player_score;

    public:
        PlayerModel();
        ~PlayerModel();

        void initialize();
        void reset();

        sf::Vector2f getPlayerPosition();
        void setPlayerPosition(sf::Vector2f position);

        int getPlayerScore();
        void setPlayerScore(int score);

        PlayerState getPlayerState();
        void setPlayerState(PlayerState state);
    };
}