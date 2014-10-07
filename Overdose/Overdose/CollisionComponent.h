#pragma once
#include "stdafx.h"
#include "Component.h"
#include "SDL.h"

namespace overdose {

	class CollisionComponent
	{
	public:
		CollisionComponent(int x, int y, int w, int h);
		~CollisionComponent();

		void setRectangle(int x, int y, int w, int h);
	private:
		SDL_Rect collisionRect;
	};


}