#include "../../Header/Element/ElementService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Collision/ICollider.h"

namespace Element
{
	using namespace Bunker;
	using namespace Collision;
	using namespace Global;

	void ElementService::spawnBunkers()
	{
		for (int i = 0; i < bunker_data_list.size(); i++)
		{
			BunkerController* bunker_controller = new BunkerController();
			bunker_controller->initialize(bunker_data_list[i]);
			bunker_list.push_back(bunker_controller);

			ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(bunker_controller));
		}
	}

	void ElementService::destroyFlaggedBunkers()
	{
		for (int i = 0; i < flagged_bunker_list.size(); i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(flagged_bunker_list[i]));
			delete (flagged_bunker_list[i]);
		}
		flagged_bunker_list.clear();
	}

	void ElementService::destroy()
	{
		for (int i = 0; i < bunker_list.size(); i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(bunker_list[i]));
			delete(bunker_list[i]);
		}
		bunker_list.clear();
	}
	ElementService::ElementService()
	{

	}
	ElementService::~ElementService()
	{
		destroy();
	}
	void ElementService::initialize()
	{
		spawnBunkers();
	}
	void ElementService::update()
	{
		for (int i = 0; i < bunker_list.size(); i++)
		{
			bunker_list[i]->update();
		}
	}
	void ElementService::render()
	{
		for (int i = 0; i < bunker_list.size(); i++)
		{
			bunker_list[i]->render();
		}
	}
	void ElementService::reset()
	{
		destroy();
		spawnBunkers();
	}
	void ElementService::destroyBunker(Bunker::BunkerController* bunker_controller)
	{
		flagged_bunker_list.push_back(bunker_controller);
		bunker_list.erase(std::remove(bunker_list.begin(), bunker_list.end(), bunker_controller), bunker_list.end());
	}
}