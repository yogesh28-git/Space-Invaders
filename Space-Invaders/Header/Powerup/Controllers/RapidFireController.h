#pragma once
#include "../../Header/Powerup/PowerupController.h"

namespace Powerup
{
	namespace Controllers
	{
		class RapidFireController : public PowerupController
		{
		public:

			RapidFireController(PowerupType type);
			~RapidFireController();

			void onCollected() override;
		};
	}
}