#pragma once
#include <SFML/Graphics.hpp>
#include "../Collision/ICollider.h"
#include "../../header/Powerup/PowerupConfig.h"

namespace Player
{
    class PlayerView;
    class PlayerModel;

    enum class PlayerState;

    class PlayerController : public Collision::ICollider
    {
    private:
        float elapsed_shield_duration;
        float elapsed_rapid_fire_duration;
        float elapsed_tripple_laser_duration;

        float elapsed_fire_duration;
        float elapsed_freez_duration;

        PlayerView* player_view;
        PlayerModel* player_model;

        void processPlayerInput();
        void moveLeft();
        void moveRight();

        bool processBulletCollision(ICollider* other_collider);
        bool processPowerupCollision(ICollider* other_collider);
        bool processEnemyCollision(ICollider* other_collider);
        void updateFreezDuration();
        void freezPlayer();

        void updateFireDuration();
        void processBulletFire();
        void FireBullets(int number_of_bullets);
        void FireBullet(sf::Vector2f position);
        
        void updatePowerupDuration();
        void processPowerup(Powerup::PowerupType power_type);
        void enableShield();
        void disableShield();
        void enableRapidFire();
        void disableRapidFire();
        void enableTrippleLaser();
        void disableTrippleLaser();

        void saveHighScore();

    public:
        PlayerController();
        ~PlayerController();

        void initialize();
        void update();
        void render();

        void reset();

        void decreasePlayerLive();
        void increaseScore(int val);
        void decreaseScore(int val);
        void increaseEnemiesKilled(int val);
        void increaseBulletsFired(int val);

        sf::Vector2f getPlayerPosition();
        PlayerState getPlayerState();

        const sf::Sprite& getColliderSprite() override;
        void onCollision(ICollider* other_collider) override;
    };
}