#include "../../header/Elements/Bunker/BunkerController.h"
#include "../../header/Elements/Bunker/BunkerView.h"

namespace Element
{
	namespace Bunker
	{
		BunkerController::BunkerController() { bunker_view = new BunkerView(); }

		BunkerController::~BunkerController() { delete(bunker_view); }

		void BunkerController::initialize(sf::Vector2f position) 
		{
			bunker_position = position;
			bunker_view->initialize(this); 
		}

		void BunkerController::update() { bunker_view->update(); }

		void BunkerController::render() { bunker_view->render(); }

		sf::Vector2f BunkerController::getBunkerPosition() { return bunker_position; }
	}
}