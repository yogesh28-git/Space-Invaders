#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Bullet/BulletConfig.h"
#include <algorithm>


namespace Player
{
	using namespace Global;
	using namespace Event;
	using namespace Bullet;

	void PlayerController::processPlayerInput()
	{
		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedLeftKey() || event_service->pressedAKey())
		{
			moveLeft();
		}

		if (event_service->pressedRightKey() || event_service->pressedDKey())
		{
			moveRight();
		}

		if (event_service->pressedLeftMouseButton())
		{
			fireBullet();
		}
	}

	void PlayerController::moveLeft()
	{
		sf::Vector2f current_position = player_model->getPlayerPosition();
		current_position.x -= player_model->movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		current_position.x = std::max(current_position.x, player_model->left_most_position.x);
		player_model->setPlayerPosition(current_position);
	}

	void PlayerController::moveRight()
	{
		sf::Vector2f current_position = player_model->getPlayerPosition();
		current_position.x += player_model->movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		current_position.x = std::min(current_position.x, player_model->right_most_position.x);
		player_model->setPlayerPosition(current_position);
	}

	void PlayerController::fireBullet()
	{
		ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::LASER, player_model->getPlayerPosition() + player_view->getBarrelPositionOffset(), MovementDirection::UP);
	}

	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView();
	}

	PlayerController::~PlayerController()
	{
		delete player_model;
		player_model = nullptr;

		delete player_view;
		player_view = nullptr;
	}

	void PlayerController::initialize()
	{
		player_model->initialize();
		player_view->initialize(this);
	}

	void PlayerController::update()
	{
		processPlayerInput();
		player_view->update();
	}

	void PlayerController::render()
	{
		player_view->render();
	}

	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return player_model->getPlayerPosition();
	}

}

