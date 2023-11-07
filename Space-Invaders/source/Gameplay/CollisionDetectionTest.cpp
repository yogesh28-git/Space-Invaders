#include "../../header/Gameplay/CollisionDetectionTest.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Event/EventService.h"

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
	processPlayerInput();
	processCollision();
}

void CollisionDetectionTest::processPlayerInput()
{
	if (ServiceLocator::getInstance()->getEventService()->pressedUpArrowKey()) moveUp();

	if (ServiceLocator::getInstance()->getEventService()->pressedDownArrowKey()) moveDown();

	if (ServiceLocator::getInstance()->getEventService()->pressedLeftArrowKey()) moveLeft();

	if (ServiceLocator::getInstance()->getEventService()->pressedRightArrowKey()) moveRight();
}

void CollisionDetectionTest::moveUp()
{
	sf::Vector2f position = rectangle_shape_one.getPosition();
	position.y -= movement_distance_per_frame;

	rectangle_shape_one.setPosition(position);
}

void CollisionDetectionTest::moveDown()
{
	sf::Vector2f position = rectangle_shape_one.getPosition();
	position.y += movement_distance_per_frame;

	rectangle_shape_one.setPosition(position);
}

void CollisionDetectionTest::moveLeft()
{
	sf::Vector2f position = rectangle_shape_one.getPosition();
	position.x -= movement_distance_per_frame;

	rectangle_shape_one.setPosition(position);
}

void CollisionDetectionTest::moveRight()
{
	sf::Vector2f position = rectangle_shape_one.getPosition();
	position.x += movement_distance_per_frame;

	rectangle_shape_one.setPosition(position);
}

void CollisionDetectionTest::processCollision()
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