#pragma once
#include "Component.h"

namespace overdose {

	class QuitOnClickComponent : public Component
	{
	private:
		bool m_clicked = false;
	public:
		QuitOnClickComponent();
		~QuitOnClickComponent();

		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();
	};

}