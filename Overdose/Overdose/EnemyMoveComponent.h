#pragma once
#include "Component.h"


namespace overdose{

	class EnemyMoveComponent : public Component
	{
	public:
		EnemyMoveComponent();
		~EnemyMoveComponent();
		void receive(Component *subject, int message, GameEntity *object);
		void tick(GameEntity *entity);
	};

}