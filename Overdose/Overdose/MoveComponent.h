#pragma once
#include "Component.h"
namespace overdose{
	class MoveComponent :
		public Component
	{
	public:
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();
	};

}