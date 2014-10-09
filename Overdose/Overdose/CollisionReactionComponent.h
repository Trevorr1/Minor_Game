#pragma once
#include "stdafx.h"
#include "Component.h"
#include "SDL.h"

namespace overdose {

	class CollisionReactionComponent :
		public Component
	{
	public:
		CollisionReactionComponent();
		~CollisionReactionComponent();

		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(GameEntity *entity);


	private:
		bool isAlive = false;
	};

}

