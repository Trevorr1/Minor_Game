#pragma once
#include "stdafx.h"
#include "CollisionReactionComponent.h"
#include "DrugComponent.h"

namespace overdose{

	class FlagCollisionReactionComponent:
		public CollisionReactionComponent
	{
	public:
		FlagCollisionReactionComponent();
		~FlagCollisionReactionComponent();

		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();
	};

}