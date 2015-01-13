#pragma once
#include "Component.h"
#include <vector>
using std::vector;
using std::string;
namespace overdose{
	class DrugDropComponent :
		public Component
	{
	private:
		GameEntity* m_Entity = nullptr;
		GameEntity* getRandomDrug();
		bool m_DropToggle = false;
	public:
		void init(GameEntity *entity);
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		string getComponentID();
	};

}