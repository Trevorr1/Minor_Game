#pragma once
#include "Component.h"
#include "InputManager.h"
namespace overdose{
	class PlayerInputComponent :
		public Component
	{
	public:
		void receive(Component *subject, int message, GameEntity *object);
		void tick(GameEntity *entity);
	};

}