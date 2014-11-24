#pragma once
#include "Component.h"

namespace overdose {

	class gravityComponent :
		public Component
	{
	public:
		gravityComponent();
		gravityComponent(float aGravity);
		virtual ~gravityComponent();

		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();

	private:
		float gravity;
		int m_terminalVelocity = 400;
	};

} // namespace overdose