#pragma once
#include "Component.h"

namespace overdose {
	class DummyComponent : public Component
	{
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(GameEntity *entity);
	};
}