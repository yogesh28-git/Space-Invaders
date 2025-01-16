
#include "../Header/TimeService.h"

// PRIVATE METHODS //

void TimeService::updateDeltaTime()
{
	delta_time = calculateDeltaTime();
	updatePreviousTime();
}

float TimeService::calculateDeltaTime()
{
	std::chrono::time_point<std::chrono::steady_clock> current_time = std::chrono::steady_clock::now();

	int elapsed_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(current_time - previous_time).count();

	return static_cast<float>(elapsed_microseconds) / static_cast<float>(1000000);
}

void TimeService::updatePreviousTime()
{
	previous_time = std::chrono::steady_clock::now();
}


// PUBLIC METHODS //

void TimeService::initialize()
{
	previous_time = std::chrono::steady_clock::now();
	delta_time = 0;
}

void TimeService::update()
{
	updateDeltaTime();
}

float TimeService::getDeltaTime()
{
	return delta_time;
}
