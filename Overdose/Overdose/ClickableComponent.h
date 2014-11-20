#pragma once
#include "Component.h"
#include "InputManager.h"

namespace overdose {
	class ClickableComponent : public Component
	{
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();
	};
}