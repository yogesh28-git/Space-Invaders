#pragma once

namespace Player
{
	class PlayerController;

	class PlayerService
	{
	private:
		PlayerController* player_controller;

	public:
		PlayerService();
		virtual ~PlayerService();

		void initialize();
		void update();
		void render();

		void enableShield();
		void enableRapidFire();
		void enableTrippleLaser();

		void reset();
	};
}