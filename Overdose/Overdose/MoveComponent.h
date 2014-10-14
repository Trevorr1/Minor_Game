#pragma once
#include "Component.h"
namespace overdose{
	class MoveComponent :
		public Component
	{
	public:
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();
	};

}