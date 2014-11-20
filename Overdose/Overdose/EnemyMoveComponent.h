#pragma once
#include "Component.h"


namespace overdose{

	class EnemyMoveComponent : public Component
	{
	private:
		int m_minX;
		int m_maxX;

	public:
		EnemyMoveComponent(int minX, int maxX);
		~EnemyMoveComponent();
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();
	};

}