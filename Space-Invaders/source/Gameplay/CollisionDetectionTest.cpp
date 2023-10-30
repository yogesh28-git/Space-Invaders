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
		rectangle_shape_one.setSize(rectangle_size);
		rectangle_shape_one.setPosition(rectangle_one_position);
		rectangle_shape_one.setFillColor(rectangle_one_color);

		rectangle_shape_two.setSize(rectangle_size);
		rectangle_shape_two.setPosition(rectangle_two_position);
		rectangle_shape_two.setFillColor(rectangle_two_color);
	}

	void CollisionDetectionTest::update()
	{
		updateRectanglePosition();
		updateRectangleColor();
	}

	void CollisionDetectionTest::updateRectanglePosition()
	{
		if (ServiceLocator::getInstance()->getEventService()->pressedLeftMouseButton())
		{
			rectangle_shape_one.setPosition(rectangle_intersection_position);
		}
		else if (ServiceLocator::getInstance()->getEventService()->pressedRightMouseButton())
		{
			rectangle_shape_one.setPosition(rectangle_one_position);
		}
	}

	void CollisionDetectionTest::updateRectangleColor()
	{
		if (rectangle_shape_one.getGlobalBounds().intersects(rectangle_shape_two.getGlobalBounds()))
		{
			rectangle_shape_one.setFillColor(rectangle_intersection_color);
			rectangle_shape_two.setFillColor(rectangle_intersection_color);
		}
		else
		{
			rectangle_shape_one.setFillColor(rectangle_one_color);
			rectangle_shape_two.setFillColor(rectangle_two_color);
		}
	}

	void CollisionDetectionTest::render()
	{
		ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->draw(rectangle_shape_one);
		ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->draw(rectangle_shape_two);
	}
}
