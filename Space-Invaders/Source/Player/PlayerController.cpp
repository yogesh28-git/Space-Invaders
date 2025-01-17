#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include <algorithm>


namespace Player
{
	using namespace Global;

	void PlayerController::processPlayerInput()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			moveLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			moveRight();
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

