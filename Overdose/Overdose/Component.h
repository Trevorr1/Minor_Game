#pragma once
#include "GameEntity.h"
#include "ComponentMessage.h"

namespace overdose {
	class GameEntity;

	class Component
	{
	public:
		virtual ~Component();
		virtual void init(GameEntity *entity);

		virtual void receive(Component *subject, ComponentMessage message, GameEntity *object) = 0;

		virtual void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) = 0;

		virtual void tick(float dt, GameEntity *entity) = 0;

		virtual std::string getComponentID() = 0;
	};
}