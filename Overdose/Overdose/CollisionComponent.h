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


		void receive(Component &component, int message);
		void tick(GameEntity *entity);
	private:
		//SDL_Rect collisionRect;
	};


}