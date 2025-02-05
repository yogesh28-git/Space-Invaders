#pragma once
#include <SFML/Graphics.hpp>

namespace Bullet
{
	class BulletController;
	enum class BulletType;

	class BulletView
	{
	private:

		float bullet_sprite_width = 18.0f;
		float bullet_sprite_height = 18.0f;

		sf::RenderWindow* game_window;

		sf::Texture bullet_texture;
		sf::Sprite bullet_sprite;

		BulletController* bullet_controller;

		void initializeImage(BulletType type);
		void scaleSprite();

	public:

		BulletView();
		~BulletView();

		void initialize(BulletController* controller);
		void update();
		void render();
	};
}
