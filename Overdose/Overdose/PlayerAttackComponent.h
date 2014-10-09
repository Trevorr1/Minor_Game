#pragma once
#include "Component.h"

namespace overdose{
	class PlayerAttackComponent : public Component
	{
	public:
		PlayerAttackComponent();
		~PlayerAttackComponent();
		void receive(Component &component, int message);
		void tick(GameEntity &entity);
	private: 
		bool attacking;
	};
}
