#pragma once
#include "../../header/Gameplay/Interface/ITest.h"

namespace Gameplay
{
	class GameplayService
	{
	private:
		Gameplay::Interface::ITest* test;

	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();
	};
}