#include "../Header/GraphicService.h"


// PRIVATE METHODS //

void GraphicService::setVideoMode()
{
	video_mode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel);
}

void GraphicService::onDestroy()
{
	delete video_mode;
	delete game_window;
}

// PUBLIC METHODS //

GraphicService::GraphicService()
{
	video_mode = nullptr;
	game_window = nullptr;
}

GraphicService::~GraphicService()
{
	onDestroy();
}


sf::RenderWindow* GraphicService::createGameWindow()
{
	setVideoMode();
	return new sf::RenderWindow(*video_mode, game_window_title);
}

void GraphicService::initialize()
{
	game_window = createGameWindow();
}

void GraphicService::update()
{
}

void GraphicService::render()
{
}

bool GraphicService::isGameWindowOpen()
{
	return game_window->isOpen();
}

sf::RenderWindow* GraphicService::getGameWindow()
{
	return game_window;
}

sf::Color GraphicService::getWindowColor()
{
	return window_color;
}
