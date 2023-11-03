#include "../../header/Elements/Bunker/BunkerView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GraphicService.h"
#include "../../header/Global/Config.h"
#include "../../header/Elements/Bunker/BunkerController.h"

namespace Element
{
	namespace Bunker
	{
		using namespace Global;
		using namespace Main;

		BunkerView::BunkerView() { }

		BunkerView::~BunkerView() { }

		void BunkerView::initialize(BunkerController* controller)
		{
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			bunker_controller = controller;
			initializeBunkerSprite();
		}

		void BunkerView::initializeBunkerSprite()
		{
			if (bunker_texture.loadFromFile(Config::bunker_texture_path))
			{
				bunker_sprite.setTexture(bunker_texture);
				bunker_sprite.setPosition(bunker_controller->getBunkerPosition());
				scaleBunkerSprite();
			}
		}

		void BunkerView::scaleBunkerSprite()
		{
			bunker_sprite.setScale(
				static_cast<float>(bunker_sprite_width) / bunker_sprite.getTexture()->getSize().x,
				static_cast<float>(bunker_sprite_height) / bunker_sprite.getTexture()->getSize().y
			);
		}

		void BunkerView::update() { }

		void BunkerView::render() { game_window->draw(bunker_sprite); }

		const sf::Sprite& BunkerView::getBunkerSprite() { return bunker_sprite; }
	}
}