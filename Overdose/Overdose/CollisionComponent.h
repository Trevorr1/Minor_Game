#pragma once
#include "stdafx.h"
#include "Component.h"
#include "SDL.h"

namespace overdose {

	class CollisionComponent : public Component
	{
	public:
		CollisionComponent(int x, int y, int w, int h);
		~CollisionComponent();

		void setRectangle(int x, int y, int w, int h);

		void receive(Component &component, int message);
		void tick(GameEntity &entity);
	private:
		SDL_Rect collisionRect;
	};


}