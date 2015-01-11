#pragma once
#include "stdafx.h"
#include "Component.h"
#include "LevelManager.h"
#include "SoundManager.h"
#include "ParticleComponent.h"
#include "KillSwitchComponent.h"
using std::vector;
namespace overdose {
	class HealthComponent : public Component
	{
	private:
		int m_health;
		bool m_scheduleHealthDecrease = false;
		vector<ComponentMessage> *m_healthDecreaseReactionList;
		vector<eGameEntity>* m_canHurt;


		float m_invincibleTime = 0;

		bool firstBlood = false;

		GameEntity *m_Subject;

	public:
		HealthComponent(int health);
		HealthComponent(int health, vector<ComponentMessage> *healthDecreaseReactionList, vector<eGameEntity>* canHurt);


		virtual ~HealthComponent();
		void init(GameEntity *entity);
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();
	};
}