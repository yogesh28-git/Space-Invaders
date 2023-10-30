#pragma once
#include "../../header/Main/GraphicService.h"
#include "../../header/Event/EventService.h"
#include "../../header/UI/UIService.h"
#include "../../header/Player/PlayerService.h"
#include "../../header/Time/TimeService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Enemy/EnemyService.h"

namespace Global
{
    class ServiceLocator
    {
    private:
        Event::EventService* event_service;
        Main::GraphicService* graphic_service;
        UI::UIService* ui_service;
        Time::TimeService* time_service;
        Sound::SoundService* sound_service;
        Player::PlayerService* player_service;
        Enemy::EnemyService* enemy_service;

        ServiceLocator();
        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Event::EventService* getEventService();
        Main::GraphicService* getGraphicService();
        UI::UIService* getUIService();
        Time::TimeService* getTimeService();
        Sound::SoundService* getSoundService();
        Player::PlayerService* getPlayerService();
        Enemy::EnemyService* getEnemyService();
        void deleteServiceLocator();
    };
}