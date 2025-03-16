#include "../../Header/Powerup/Controllers/TrippleLaserController.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Powerup
{
	namespace Controllers
	{

		using namespace Global;

		TrippleLaserController::TrippleLaserController(PowerupType type) : PowerupController(type)
		{
		}

		TrippleLaserController::~TrippleLaserController()
		{
		}
		void TrippleLaserController::onCollected()
		{
			applyPowerup();
		}
		void TrippleLaserController::applyPowerup()
		{
			ServiceLocator::getInstance()->getPlayerService()->enableTrippleLaser();
		}
	}
}