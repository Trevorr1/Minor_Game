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
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();

	private:
		//SDL_Rect collisionRect;

		struct Point {
			int x;
			int y;
		};

		struct cPoint {
			Point first;
			Point second;
		} *cPoints[4];
	};


}