#pragma once
#include "Component.h"


namespace overdose{

	class EnemyMoveComponent : public Component
	{
	public:
		EnemyMoveComponent();
		~EnemyMoveComponent();
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(float dt, GameEntity *entity);
	};

}