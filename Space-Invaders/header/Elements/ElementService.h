#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../header/Elements/Bunker/BunkerController.h"

namespace Element
{
	class BunkerController;

	class ElementService
	{
	private:
		const std::vector<sf::Vector2f> bunker_position_list = { sf::Vector2f(130.f, 800.f),
																sf::Vector2f(430.0f, 800.f),
																sf::Vector2f(730.0f, 800.f),
																sf::Vector2f(1130.0f, 800.f),
																sf::Vector2f(1430.0f, 800.f),
																sf::Vector2f(1730.0f, 800.f) };

		std::vector<Bunker::BunkerController*> bunker_list;

		void destroy();

	public:
		ElementService();
		virtual ~ElementService();

		void initialize();
		void update();
		void render();
	};
}