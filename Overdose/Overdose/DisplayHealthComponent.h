#pragma once
#include "Component.h"
using std::string;
namespace overdose{
	class DisplayHealthComponent :
		public Component
	{
	public:

		DisplayHealthComponent();
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		string getComponentID();
	};

}