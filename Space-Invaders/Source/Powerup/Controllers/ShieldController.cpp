#include "../../Header/Powerup/Controllers/ShieldController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Powerup
{
	namespace Controllers
	{
		using namespace Global;

		Powerup::Controllers::ShieldController::ShieldController(PowerupType type) : PowerupController(type)
		{
		}

		Powerup::Controllers::ShieldController::~ShieldController()
		{
		}
		void ShieldController::onCollected()
		{
			applyPowerup();
		}
		void ShieldController::applyPowerup()
		{
			ServiceLocator::getInstance()->getPlayerService()->enableShield();
		}
	}
}