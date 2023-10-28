#include "../../header/UI/UIService.h"
#include "../../header/Main/GameService.h"

namespace UI
{
	using namespace Main;
	using namespace Interface;

	UIService::UIService()
	{
		createControllers();
	}

	UIService::~UIService()
	{
		destroy();
	}

	void UIService::createControllers() { }

	void UIService::initialize()
	{
		initializeControllers();
	}

	void UIService::update()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->update();
	}

	void UIService::render()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->render();
	}

	void UIService::showScreen()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->show();
	}

	void UIService::initializeControllers() { }

	IUIController* UIService::getCurrentUIController()
	{
		return nullptr;
	}

	void UIService::destroy() { }
}