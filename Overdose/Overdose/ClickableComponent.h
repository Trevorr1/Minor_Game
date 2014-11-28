#pragma once
#include "MouseBaseComponent.h"


namespace overdose {
	class ClickableComponent : public MouseBaseComponent
	{
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();
	};
}