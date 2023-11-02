#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerView.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Event/EventService.h"
#include "../../header/Bullet/BulletConfig.h"

namespace Player
{
	using namespace Global;
	using namespace Event;
	using namespace Time;
	using namespace Bullet;

	PlayerController::PlayerController()
	{
		player_view = new PlayerView();
		player_model = new PlayerModel();
	}

	PlayerController::~PlayerController()
	{
		delete (player_view);
		delete (player_model);
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

	int PlayerController::getPlayerScore()
	{
		return player_model->getPlayerScore();
	}

	PlayerState PlayerController::getPlayerState()
	{
		return player_model->getPlayerState();
	}

	const sf::Sprite& PlayerController::getColliderSprite()
	{
		return player_view->getPlayerSprite();
	}

	void PlayerController::onCollision(ICollider* other_collider)
	{
	}

	void PlayerController::processPlayerInput()
	{
		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedLeftArrowKey()) moveLeft();	
		if (event_service->pressedRightArrowKey()) moveRight();
		if (event_service->pressedLeftMouseButton()) FireBullet();
	}

	void PlayerController::moveLeft()
	{
		sf::Vector2f currentPosition = player_model->getPlayerPosition();
		currentPosition.x -= player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::max(currentPosition.x, left_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}

	void PlayerController::moveRight()
	{
		sf::Vector2f currentPosition = player_model->getPlayerPosition();
		currentPosition.x += player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::min(currentPosition.x, right_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}

	void PlayerController::FireBullet()
	{
		ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::FROST_BEAM,
			player_model->getPlayerPosition() + barrel_position_offset,
			Bullet::MovementDirection::UP);
	}
}