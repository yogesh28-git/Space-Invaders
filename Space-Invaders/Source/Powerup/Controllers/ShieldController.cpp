#include "../../Header/Powerup/Controllers/ShieldController.h"


namespace Powerup
{
	namespace Controllers
	{

		Powerup::Controllers::ShieldController::ShieldController(PowerupType type) : PowerupController(type)
		{
		}

		Powerup::Controllers::ShieldController::~ShieldController()
		{
		}
		void ShieldController::onCollected()
		{
		}
	}
}