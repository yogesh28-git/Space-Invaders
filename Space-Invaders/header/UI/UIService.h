#pragma once
#include "../../header/UI/Interface/IUIController.h"

namespace UI
{
	class UIService
	{
	private:
		void createControllers();
		void initializeControllers();
		Interface::IUIController* getCurrentUIController();
		void destroy();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
		void showScreen();
	};
}