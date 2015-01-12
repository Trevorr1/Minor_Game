#pragma once
#include "Component.h"
#include <ctime>

namespace overdose 
{
	class DrugOscillationComponent :
		public Component
	{
	public:
		DrugOscillationComponent();
		virtual ~DrugOscillationComponent();

		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();

	private:
		std::clock_t m_Begin;
	};
}//namespace overdose

