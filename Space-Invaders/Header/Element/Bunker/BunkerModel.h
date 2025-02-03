#pragma once
#include <SFML/Graphics.hpp>

namespace Element
{
	namespace Bunker
	{
		struct BunkerData
		{
			sf::Vector2f position;

			BunkerData();
			BunkerData(sf::Vector2f pos);
		};
	}
}
