#pragma once
#include "Component.h"

namespace overdose{
	class URLClickComponent :
		public Component
	{
	public:
		URLClickComponent(std::string URL);
		~URLClickComponent();

		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();

	private:
		std::string m_URL;
		bool m_clicked = false;
	};

}
