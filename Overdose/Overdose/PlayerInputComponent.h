#pragma once
#include "Component.h"
#include "InputManager.h"
namespace overdose{
	class PlayerInputComponent :
		public Component
	{
	public:
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(GameEntity *entity);
	};

}