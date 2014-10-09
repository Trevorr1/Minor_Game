#pragma once
#include "Component.h"

namespace overdose{
	class PlayerAttackComponent : public Component
	{
	public:
		PlayerAttackComponent();
		~PlayerAttackComponent();
		void receive(Component *subject, int message, GameEntity *object);
		void tick(GameEntity &entity);
	private: 
		bool attacking;
	};
}
