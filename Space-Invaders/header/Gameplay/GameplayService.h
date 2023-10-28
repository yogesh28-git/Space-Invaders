#pragma once

namespace Gameplay
{
	class GameplayService
	{
	private:

	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();
	};
}