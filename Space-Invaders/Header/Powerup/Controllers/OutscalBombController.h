#pragma once
#include "../../Header/Powerup/PowerupController.h"

namespace Powerup
{
	namespace Controllers
	{
		class OutscalBombController : public PowerupController
		{
		public:

			OutscalBombController( PowerupType type );
			~OutscalBombController();

			void onCollected() override;
			void applyPowerup() override;
		};
	}
}
