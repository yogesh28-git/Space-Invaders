#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    enum class EnemyState
    {
        ALIVE,
        DEAD,
    };

    enum class MovementDirection
    {
        LEFT,
        RIGHT,
        DOWN,
    };

    class EnemyModel
    {
    private:
        sf::Vector2f reference_position = sf::Vector2f(50.f, 50.f);
        sf::Vector2f enemy_position;
        EnemyState enemy_state;
        MovementDirection movement_direction;

    public:
        EnemyModel();
        ~EnemyModel();

        void initialize();

        sf::Vector2f getEnemyPosition();
        void setEnemyPosition(sf::Vector2f position);

        sf::Vector2f getReferencePosition();
        void setReferencePosition(sf::Vector2f position);

        EnemyState getEnemyState();
        void setEnemyState(EnemyState state);

        MovementDirection getMovementDirection();
        void setMovementDirection(MovementDirection direction);
    };
}