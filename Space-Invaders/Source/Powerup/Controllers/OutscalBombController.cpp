#include "../../Header/Powerup/Controllers/OutscalBombController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Powerup
{
	namespace Controllers
	{
		using namespace Global;

		OutscalBombController::OutscalBombController(PowerupType type) : PowerupController(type)
		{
		}
		OutscalBombController::~OutscalBombController()
		{
		}
		void OutscalBombController::onCollected()
		{
			applyPowerup();
		}
		void OutscalBombController::applyPowerup()
		{
			ServiceLocator::getInstance()->getEnemyService()->reset();
		}
	}
}