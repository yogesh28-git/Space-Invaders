#include "../../header/Gameplay/SFMLTest.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GraphicService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Main;

	void SFMLTest::initialize()
	{
		rectangle_shape = sf::RectangleShape(sf::Vector2f(200, 200));
		rectangle_shape.setFillColor(sf::Color::Red);
		rectangle_shape.setPosition(860, 460);
	}

	void SFMLTest::update() { }

	void SFMLTest::render()
	{
		ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->draw(rectangle_shape);
	}
}