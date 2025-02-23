#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

namespace Bullet
{
	class BulletController;
	enum class BulletType;

	class BulletView
	{
	private:

		float bullet_sprite_width = 18.0f;
		float bullet_sprite_height = 18.0f;

		BulletController* bullet_controller;
		UI::UIElement::ImageView* bullet_image;

		void createUIElements();
		void initializeImage();
		sf::String getBulletTexturePath();
		void destroy();

	public:

		BulletView();
		~BulletView();

		void initialize(BulletController* controller);
		void update();
		void render();
	};
}
