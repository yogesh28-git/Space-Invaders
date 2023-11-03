#pragma once
#include <SFML/Graphics.hpp>
#include "../Collision/ICollider.h"

namespace Enemy
{
    class EnemyView;
    class EnemyModel;

    enum class EnemyType;
    enum class EnemyState;

    class EnemyController : public Collision::ICollider
    {
    protected:
        const sf::Vector2f left_most_position = sf::Vector2f(50.f, 50.f);
        const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 50.f);
        const sf::Vector2f barrel_position_offset = sf::Vector2f(20.f, 50.f);

        float vertical_movement_speed = 30.f;
        float horizontal_movement_speed = 200.0f;

        float cooldown_fire_duration = 3.f;
        float elapsed_fire_duration = 0.f;

        EnemyView* enemy_view;
        EnemyModel* enemy_model;

        void updateFireTimer();
        void processBulletFire();
        virtual void fireBullet() = 0;

        void updateEnemyPosition();
        virtual void moveLeft() = 0;
        virtual void moveRight() = 0;
        virtual void moveDown() = 0;
        virtual void moveDiagonalLeft() = 0;
        virtual void moveDiagonalRight() = 0;

        sf::Vector2f getRandomInitialPosition();
       
    public:
        EnemyController(EnemyType type);
        virtual ~EnemyController();

        virtual void initialize();
        void update();
        void render();

        sf::Vector2f getEnemyPosition();
        EnemyState getEnemyState();
        EnemyType getEnemyType();

        const sf::Sprite& getColliderSprite() override;
        virtual void onCollision(ICollider* other_collider) override;
    };
}