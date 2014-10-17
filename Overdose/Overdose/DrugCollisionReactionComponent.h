#pragma once
#include "stdafx.h"
#include "CollisionReactionComponent.h"
#include "DrugComponent.h"


namespace overdose{

	class DrugCollisionReactionComponent :
		public CollisionReactionComponent
	{
	public:
		DrugCollisionReactionComponent();
		virtual ~DrugCollisionReactionComponent();

		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();

	private:
		bool isCollided = false;
		DrugComponent *drugComponent = NULL;
	};


}