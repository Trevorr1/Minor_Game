#pragma once
#include "Component.h"
#include "LevelManager.h"

namespace overdose{

	class FocusPointerComponent :
		public Component
	{
	public:
		enum CursorColor{ YELLOW, RED };

		FocusPointerComponent(GameEntity* entity, CursorColor color);
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