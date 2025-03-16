#pragma once
#include "../../Header/Powerup/PowerupController.h"

namespace Powerup
{
	namespace Controllers
	{
		class ShieldController : public PowerupController
		{
		public:

			ShieldController(PowerupType type);
			~ShieldController();

			void onCollected() override;
			void applyPowerup() override;
		};
	}
}