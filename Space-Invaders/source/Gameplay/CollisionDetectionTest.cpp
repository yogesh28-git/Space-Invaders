#include "../../header/Gameplay/CollisionDetectionTest.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GraphicService.h"
#include "../../header/Event/EventService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Main;
	using namespace Event;

	void CollisionDetectionTest::initialize()
	{
		rectangle_shape_one.setSize(sf::Vector2f(150, 150));
		rectangle_shape_one.setPosition(600, 400);
		rectangle_shape_one.setFillColor(sf::Color::Red);

		rectangle_shape_two.setSize(sf::Vector2f(150, 150));
		rectangle_shape_two.setPosition(850, 550);
		rectangle_shape_two.setFillColor(sf::Color::Green);
	}

	void CollisionDetectionTest::update()
	{
		updateRectanglePosition();

		if (rectangle_shape_one.getGlobalBounds().intersects(rectangle_shape_two.getGlobalBounds())) 
		{
			rectangle_shape_one.setFillColor(sf::Color::Yellow);
			rectangle_shape_two.setFillColor(sf::Color::Yellow);
		}
		else 
		{
			rectangle_shape_one.setFillColor(sf::Color::Red);
			rectangle_shape_two.setFillColor(sf::Color::Green);
		}
	}

	void CollisionDetectionTest::updateRectanglePosition()
	{
		if (ServiceLocator::getInstance()->getEventService()->pressedLeftMouseButton())
		{
			rectangle_shape_one.setPosition(900, 450);
		}
		else if (ServiceLocator::getInstance()->getEventService()->pressedRightMouseButton())
		{
			rectangle_shape_one.setPosition(600, 400);
		}
	}

	void CollisionDetectionTest::render()
	{
		ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->draw(rectangle_shape_one);
		ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->draw(rectangle_shape_two);
	}
}
