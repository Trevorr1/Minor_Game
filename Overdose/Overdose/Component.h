#pragma once
#include "GameEntity.h"
namespace overdose {
	class GameEntity;

	class Component
	{
	public:

		virtual void receive(Component *subject, int message, GameEntity *object) = 0;

		

		virtual void tick(GameEntity *entity) = 0;
	};
}