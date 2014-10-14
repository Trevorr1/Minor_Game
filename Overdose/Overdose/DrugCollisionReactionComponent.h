#pragma once
#include "stdafx.h"
#include "CollisionReactionComponent.h"

namespace overdose{

	class DrugCollisionReactionComponent :
		public CollisionReactionComponent
	{
	public:
		DrugCollisionReactionComponent();
		virtual ~DrugCollisionReactionComponent();

		void tick(float dt, GameEntity *entity);
	};

}