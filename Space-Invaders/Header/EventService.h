#pragma once

#include <SFML/Graphics.hpp>

class EventService
{
private:

	sf::Event game_event;
	sf::RenderWindow* game_window;

	bool isGameWindowOpen();
	bool gameWindowWasClosed();
	bool hasQuitGame();


public:

	EventService();
	~EventService();

	void initialize();
	void update();
	void processEvents();
	bool pressedEscapeKey();
	bool isKeyboardEvent();

	bool pressedLeftKey();
	bool pressedRightKey();
};
