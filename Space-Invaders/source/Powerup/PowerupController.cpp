#include "../../header/Powerup/PowerupController.h"
#include "../../header/Powerup/PowerupView.h"
#include "../../header/Powerup/PowerupModel.h"
#include "../../header/Global/ServiceLocator.h"

namespace Powerup
{
	using namespace Global;

	PowerupController::PowerupController(PowerupType type)
	{
		powerup_view = new PowerupView();
		powerup_model = new PowerupModel(type);
	}

	PowerupController::~PowerupController()
	{
		delete (powerup_view);
		delete (powerup_model);
	}

	void PowerupController::initialize(sf::Vector2f position)
	{
		powerup_model->initialize(position);
		powerup_view->initialize(this);
	}

	void PowerupController::update()
	{
		updatePowerupPosition();
		powerup_view->update();
	}

	void PowerupController::render()
	{
		powerup_view->render();
	}

	void PowerupController::updatePowerupPosition()
	{
		sf::Vector2f currentPosition = powerup_model->getPowerupPosition();
		currentPosition.y += movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		powerup_model->setPowerupPosition(currentPosition);
	}

	sf::Vector2f PowerupController::getPowerupPosition()
	{
		return powerup_model->getPowerupPosition();
	}

	PowerupType PowerupController::getPowerupType()
	{
		return powerup_model->getPowerupType();
	}
}