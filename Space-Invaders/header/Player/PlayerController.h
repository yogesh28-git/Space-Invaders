#pragma once
#include <SFML/Graphics.hpp>
#include "../Collision/ICollider.h"

namespace Player
{
    class PlayerView;
    class PlayerModel;

    enum class PlayerState;

    class PlayerController : public Collision::ICollider
    {
    private:
        const float player_movement_speed = 350.0f;

        const sf::Vector2f left_most_position = sf::Vector2f(50.f, 950.f);
        const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 950.f);
        const sf::Vector2f barrel_position_offset = sf::Vector2f(20.f, 5.f);

        PlayerView* player_view;
        PlayerModel* player_model;

        void processPlayerInput();
        void moveLeft();
        void moveRight();

        void FireBullet();

    public:
        PlayerController();
        ~PlayerController();

        void initialize();
        void update();
        void render();

        sf::Vector2f getPlayerPosition();
        int getPlayerScore();
        PlayerState getPlayerState();

        const sf::Sprite& getColliderSprite() override;
        void onCollision(ICollider* other_collider) override;
    };
}