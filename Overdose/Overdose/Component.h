#pragma once
#include "GameEntity.h"
#include "ComponentMessage.h"

namespace overdose {
	class GameEntity;

	class Component
	{
	public:

		virtual void receive(Component *subject, ComponentMessage message, GameEntity *object) = 0;

		

		virtual void tick(GameEntity *entity) = 0;
	};
}