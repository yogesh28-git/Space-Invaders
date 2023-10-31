#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    class EnemyView;
    class EnemyModel;

    enum class EnemyType;
    enum class EnemyState;

    class EnemyController
    {
    protected:
        const sf::Vector2f left_most_position = sf::Vector2f(50.f, 950.f);
        const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 950.f);

        float vertical_travel_distance = 100.f;
        float enemy_movement_speed = 250.0f;

        EnemyView* enemy_view;
        EnemyModel* enemy_model;

        void updateEnemyPosition();
        virtual void moveLeft() = 0;
        virtual void moveRight() = 0;
        virtual void moveDown() = 0;
        virtual void moveDiagonalLeft() = 0;
        virtual void moveDiagonalRight() = 0;

    public:
        EnemyController(EnemyType type);
        virtual ~EnemyController();

        virtual void initialize();
        void update();
        void render();

        sf::Vector2f getEnemyPosition();
        EnemyState getEnemyState();
        EnemyType getEnemyType();
    };
}