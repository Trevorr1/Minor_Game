#pragma once
#include "stdafx.h"
#include "Component.h"
#include "SDL.h"

namespace overdose {

	class CollisionComponent : public Component
	{
	public:
		CollisionComponent();
		~CollisionComponent();


		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(GameEntity *entity);
	private:
		//SDL_Rect collisionRect;
	};


}