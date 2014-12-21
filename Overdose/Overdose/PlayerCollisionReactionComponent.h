#pragma once
#include "stdafx.h"
#include "CollisionReactionComponent.h"

namespace overdose{

	class PlayerCollisionReactionComponent :
		public CollisionReactionComponent
	{
	public:
		PlayerCollisionReactionComponent();
		~PlayerCollisionReactionComponent();

		void tick(float dt, GameEntity *entity);
		std::string getComponentID();
	private:
		void resolveTopCollision(GameEntity *entity);
		void resolveBotCollision(GameEntity *entity);
		void resolveLeftCollision(GameEntity *entity);
		void resolveRightCollision(GameEntity *entity);
	};
}

