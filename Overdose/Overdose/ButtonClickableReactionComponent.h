#pragma once
#include "Component.h"
#include "LevelManager.h"

namespace overdose {
	class ButtonClickableReactionComponent : public Component
	{
	private:
		bool m_clicked = false;
		levels m_loadScreen;

	public:
		ButtonClickableReactionComponent(levels loadScreen);
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();
	};
}