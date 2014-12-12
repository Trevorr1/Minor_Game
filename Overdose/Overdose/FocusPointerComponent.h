#pragma once
#include "Component.h"
#include "LevelManager.h"

namespace overdose{

	class FocusPointerComponent :
		public Component
	{
	public:
		FocusPointerComponent(GameEntity* entity);
		~FocusPointerComponent();
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();

	private:
		GameEntity* entity;

		GameEntity *tutorial;
	};

}