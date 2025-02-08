#include "../../Header/Powerup/PowerupController.h"
#include "../../Header/Powerup/PowerupModel.h"
#include "../../Header/Powerup/PowerupView.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Powerup
{
	using namespace Global;

	void PowerupController::updatePowerupPosition()
	{
		sf::Vector2f current_position = powerup_model->getPowerupPosition();

		current_position.y += powerup_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		powerup_model->setPowerupPosition(current_position);
	}
	void PowerupController::handleOutOfBounds()
	{
		sf::Vector2f powerup_position = powerup_model->getPowerupPosition();
		sf::Vector2u window_size = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (powerup_position.x < 0 || powerup_position.y < 0 || powerup_position.x > window_size.x || powerup_position.y > window_size.y)
		{
			ServiceLocator::getInstance()->getPowerupService()->destroyPowerup(this);
		}
	}
	PowerupController::PowerupController(PowerupType type)
	{
		powerup_model = new PowerupModel(type);
		powerup_view = new PowerupView();
	}
	PowerupController::~PowerupController()
	{
		delete powerup_model;
		powerup_model = nullptr;

		delete powerup_view;
		powerup_view = nullptr;
	}
	void PowerupController::initialize(sf::Vector2f position)
	{
		powerup_view->initialize(this);
		powerup_model->initialize(position);
	}
	void PowerupController::update()
	{
		powerup_view->update();
	}
	void PowerupController::render()
	{
		powerup_view->render();
	}
	void PowerupController::onCollected()
	{

	}
	sf::Vector2f PowerupController::getCollectiblePosition()
	{
		return powerup_model->getPowerupPosition();
	}
	PowerupType PowerupController::getPowerupType()
	{
		return powerup_model->getPowerupType();
	}
}