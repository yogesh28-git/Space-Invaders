#pragma once
#include <SFML/Graphics.hpp>

namespace Gameplay {

	class GameplayView {
	private:

		sf::Texture background_texture;
		sf::Sprite background_sprite;

		sf::RenderWindow* game_window;

		void initializeBackground();
		void scaleBackground();

	public:
		GameplayView();
		~GameplayView();

		void initialize();
		void update();
		void render();
	};
}