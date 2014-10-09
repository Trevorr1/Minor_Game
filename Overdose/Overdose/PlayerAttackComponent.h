#pragma once
#include "Component.h"

namespace overdose{
	class PlayerAttackComponent : public Component
	{
	public:
		PlayerAttackComponent();
		~PlayerAttackComponent();
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(GameEntity &entity);
	};
}
