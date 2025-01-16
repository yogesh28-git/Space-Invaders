#include "../Header/ServiceLocator.h"

ServiceLocator::ServiceLocator()
{
	graphic_service = nullptr;
	time_service = nullptr;
	event_service = nullptr;
	player_service = nullptr;
	createServices();
}

ServiceLocator::~ServiceLocator()
{
	clearAllServices();
}

void ServiceLocator::createServices()
{
	graphic_service = new GraphicService();
	time_service = new TimeService();
	event_service = new EventService();
	player_service = new PlayerService();
}

void ServiceLocator::clearAllServices()
{
	delete graphic_service;
	graphic_service = nullptr;

	delete time_service;
	time_service = nullptr;

	delete event_service;
	event_service = nullptr;

	delete player_service;
	player_service = nullptr;
	
}

ServiceLocator* ServiceLocator::getInstance()
{
	static ServiceLocator instance;
	return &instance;
}

void ServiceLocator::initialize()
{
	graphic_service->initialize();
	time_service->initialize();
	event_service->initialize();
	player_service->initialize();
}

void ServiceLocator::update()
{
	graphic_service->update();
	time_service->update();
	event_service->update();
	player_service->update();
}

void ServiceLocator::render()
{
	graphic_service->render();
	player_service->render();
}

EventService* ServiceLocator::getEventService()
{
	return event_service;
}

GraphicService* ServiceLocator::getGraphicService()
{
	return graphic_service;
}

PlayerService* ServiceLocator::getPlayerService()
{
	return player_service;
}

TimeService* ServiceLocator::getTimeService()
{
	return time_service;
}


