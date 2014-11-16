#pragma once
#include "Component.h"
#include "InputManager.h"
#include "LevelManager.h"
namespace overdose{
	class PlayerInputComponent :
		public Component
	{
	public:
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();
	};

}