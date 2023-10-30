#include "../../header/Gameplay/SFMLTest.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GraphicService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Main;

	void SFMLTest::initialize()
	{
		rectangle_shape = sf::RectangleShape(sf::Vector2f(rectangle_width, rectangle_height));
		rectangle_shape.setFillColor(rectangle_color);
		rectangle_shape.setPosition(rectangle_position);
	}

	void SFMLTest::update() { }

	void SFMLTest::render()
	{
		ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->draw(rectangle_shape);
	}
}