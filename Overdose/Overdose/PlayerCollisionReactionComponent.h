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
	};
}

