#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    class EnemyView;
    class EnemyModel;

    enum class EnemyState;

    class EnemyController
    {
    private:
        const sf::Vector2f left_most_position = sf::Vector2f(50.f, 950.f);
        const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 950.f);
        const sf::Vector2f initial_position = sf::Vector2f(50.f, 50.f);

        const float enemy_movement_speed = 150.0f;

        EnemyView* enemy_view;
        EnemyModel* enemy_model;

        void updateEnemyPosition();
        void moveLeft();
        void moveRight();
        void moveDown();

    public:
        EnemyController();
        ~EnemyController();

        void initialize();
        void update();
        void render();

        sf::Vector2f getEnemyPosition();
        EnemyState getEnemyState();
    };
}