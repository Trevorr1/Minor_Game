#pragma once
#include "GameEntity.h"
namespace overdose {
	class GameEntity;

	class Component
	{
	public:

		virtual void receive(Component &component, int message) = 0;

		virtual void tick(GameEntity &entity) = 0;
	};
}