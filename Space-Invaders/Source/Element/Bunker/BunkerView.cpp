#include "../../Header/Element/Bunker/BunkerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Element/Bunker/BunkerController.h"
#include "../../Header/Global/Config.h"

namespace Element
{
	namespace Bunker
	{
		using namespace Global;

		void BunkerView::scaleSprite()
		{
			float factorX = bunker_sprite_width / bunker_sprite.getTexture()->getSize().x;
			float factorY = bunker_sprite_height / bunker_sprite.getTexture()->getSize().y;
			bunker_sprite.setScale(factorX, factorY);
		}
		void BunkerView::initializeImage()
		{
			if (bunker_texture.loadFromFile(Config::bunker_texture_path))
			{
				bunker_sprite.setTexture(bunker_texture);
				scaleSprite();
			}
		}
		BunkerView::BunkerView()
		{
			game_window = nullptr;
		}
		BunkerView::~BunkerView()
		{
		}
		void BunkerView::initialize(BunkerController* controller)
		{
			bunker_controller = controller;
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			initializeImage();
		}
		void BunkerView::update()
		{
			bunker_sprite.setPosition(bunker_controller->getBunkerPosition());
		}
		void BunkerView::render()
		{
			game_window->draw(bunker_sprite);
		}
	}
}