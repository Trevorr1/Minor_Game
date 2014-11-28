#pragma once
#include "Component.h"

namespace overdose {
	class DeleteEntityClickComponent :
		public Component
	{
	public:
		DeleteEntityClickComponent();
		~DeleteEntityClickComponent();

		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();
	private:
		bool m_clicked = false;
	};

}