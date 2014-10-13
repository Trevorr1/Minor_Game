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
		void tick(float dt, GameEntity *entity);

		// Handle collision with environment
		void environmentCollision(GameEntity *subject, GameEntity *object);


	private:
		bool isAlive = true, collidedTop = false, collidedBottom = false, collidedX = false;
	};

}

