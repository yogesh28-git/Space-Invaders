#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD
	};

	class PlayerModel
	{
	private:

		const sf::Vector2f initial_position = sf::Vector2f(100.0f, 100.0f);
		sf::Vector2f player_position;
		PlayerState player_state;
		int player_score = 0;

	public:

		const sf::Vector2f left_most_position = sf::Vector2f(50.0f, 0.0f);
		const sf::Vector2f right_most_position = sf::Vector2f(700.0f, 0.0f);

		const float movement_speed = 350.0f;

		PlayerModel();
		~PlayerModel();

		void initialize();

		void reset();

		//getters and setters
		sf::Vector2f getPlayerPosition();
		void setPlayerPosition(sf::Vector2f position);

		int getPlayerScore();
		void setPlayerScore(int score);

		PlayerState getPlayerState();
		void setPlayerState(PlayerState state);
	};

}

