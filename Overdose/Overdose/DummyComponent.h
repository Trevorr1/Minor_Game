#pragma once
#include "Component.h"

namespace overdose {
	class DummyComponent : public Component
	{
		void receive(Component *subject, int message, GameEntity *object);
		void tick(GameEntity *entity);
	};
}