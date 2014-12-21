#pragma once
#include "stdafx.h"
#include "Component.h"
#include "SDL.h"

namespace overdose {

	class CollisionComponent : public Component
	{
	public:
		CollisionComponent();
		virtual ~CollisionComponent();


		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();

	private:
		struct Point {
			int x;
			int y;
		};

		struct cPoint {
			Point first;
			Point second;
		} *cPoints[4];

		void resolveTopCollision(GameEntity *entity, GameEntity *other);
		void resolveBotCollision(GameEntity *entity, GameEntity *other);
		void resolveLeftCollision(GameEntity *entity, GameEntity *other);
		void resolveRightCollision(GameEntity *entity, GameEntity *other);

		void updateCPoints(GameEntity *entity);
	};
}