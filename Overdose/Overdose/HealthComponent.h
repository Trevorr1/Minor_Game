#pragma once
#include "stdafx.h"
#include "Component.h"

namespace overdose {
	class HealthComponent : public Component
	{
	private:
		int m_health;
		bool m_scheduleHealthDecrease = false;
		std::vector<ComponentMessage> *m_healthDecreaseReactionList;

		float m_invincibleTime = 0;

	public:
		HealthComponent(int health);
		HealthComponent(int health, std::vector<ComponentMessage> *healthDecreaseReactionList );


		virtual ~HealthComponent();
		void init(GameEntity *entity);
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();
	};
}