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
		virtual void tick(float dt, GameEntity *entity) = 0;


	protected:
		bool isAlive = true, collidedTop = false, collidedBottom = false, collidedX = false;
	};

}

