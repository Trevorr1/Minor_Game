#pragma once
#include "Component.h"
namespace overdose{
	class MoveComponent :
		public Component
	{
	public:
		void receive(Component *subject, int message, GameEntity *object);
		void tick(GameEntity *entity);
	};

}