#pragma once
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Event/EventService.h"
#include "../../header/UI/UIService.h"
#include "../../header/Gameplay/GameplayService.h"

class ServiceLocator
{
private:
    EventService* event_service;
    GraphicService* graphic_service;
    UIService* ui_service;
    GameplayService* gameplay_service;

    ServiceLocator();
    ~ServiceLocator();

    void createServices();
    void clearAllServices();

public:
    static ServiceLocator* getInstance();

    void initialize();
    void update();
    void render();

    EventService* getEventService();
    GraphicService* getGraphicService();
    UIService* getUIService();
    GameplayService* getGameplayService();
    void deleteServiceLocator();
};