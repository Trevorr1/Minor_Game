#pragma once
#include "Component.h"
#include "Level.h"

namespace overdose {
	class GameEntity;
	class Level;

	class Component
	{
	public:

		virtual void receive(Component &component, int message) = 0;

		virtual void tick(GameEntity &entity, Level &level) = 0;
	};
}