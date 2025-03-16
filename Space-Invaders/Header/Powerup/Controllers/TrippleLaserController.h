#pragma once
#include "../../Header/Powerup/PowerupController.h"

namespace Powerup
{
	namespace Controllers
	{
		class TrippleLaserController : public PowerupController
		{
		public:

			TrippleLaserController(PowerupType type);
			~TrippleLaserController();

			void onCollected() override;
			void applyPowerup() override;
		};
	}
}