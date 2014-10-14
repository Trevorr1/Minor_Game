#pragma once
#include "CollisionReactionComponent.h"

namespace overdose{

	class PolicemanCollisionReactionComponent :
		public CollisionReactionComponent
	{
	public:
		PolicemanCollisionReactionComponent();
		virtual ~PolicemanCollisionReactionComponent();

		void tick(float dt, GameEntity *entity);
		std::string getComponentID();
	};

}
