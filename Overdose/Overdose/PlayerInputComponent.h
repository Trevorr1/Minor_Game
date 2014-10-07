#pragma once
#include "Component.h"
#include "InputManager.h"
namespace overdose{
	class PlayerInputComponent :
		public Component
	{
	public:
		void receive(Component &component, int message);
		void tick(GameEntity &entity);
	};

}