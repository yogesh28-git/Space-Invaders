#pragma once

class GameService
{
private:
	void initialize();
	void destroy();

public:
	GameService();
	~GameService();

	void ignite();
	void update();
	void render();
	bool isRunning();
};
