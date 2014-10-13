#pragma once
#include "Component.h"
#include "InputManager.h"

namespace overdose {
	class ClickableComponent : public Component
	{
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(float dt, GameEntity *entity);
	};
}