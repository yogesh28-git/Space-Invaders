#include "../../Header/Element/Bunker/BunkerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Element/Bunker/BunkerController.h"
#include "../../Header/Global/Config.h"

namespace Element
{
	namespace Bunker
	{
		using namespace Global;
		using namespace UI::UIElement;

		void BunkerView::createUIElements()
		{
			bunker_image = new ImageView();
		}
		void BunkerView::initializeImage()
		{
			bunker_image->initialize(getBunkerTexturePath(), bunker_sprite_width, bunker_sprite_height, bunker_controller->getBunkerPosition());
		}
		sf::String BunkerView::getBunkerTexturePath()
		{
			return Config::bunker_texture_path;
		}
		BunkerView::BunkerView()
		{
			createUIElements();
		}
		BunkerView::~BunkerView()
		{
		}
		void BunkerView::initialize(BunkerController* controller)
		{
			bunker_controller = controller;
			initializeImage();
		}
		void BunkerView::update()
		{
			bunker_image->update();
			bunker_image->setPosition(bunker_controller->getBunkerPosition());
		}
		void BunkerView::render()
		{
			bunker_image->render();
		}
		const sf::Sprite& BunkerView::getBunkerSprite()
		{
			return bunker_image->getSprite();
		}
	}
}