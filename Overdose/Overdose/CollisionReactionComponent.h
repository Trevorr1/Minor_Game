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
		std::string getComponentID();

	protected:
		bool isAlive = true, collidedTop = false, collidedBottom = false, collidedLeft = false,
			collidedRight = false, reactTop = false, reactBottom = false, reactLeft = false, reactRight = false;
		int colX = 0, colY = 0, colBoxX = 0, colBoxY = 0;
	};

}

