#pragma once
#include "Component.h"
#include "LevelManager.h"
#include "MoveComponent.h"
#include "DrawComponent.h"
#include "KillSwitchComponent.h"
using std::string;
namespace overdose{
	class ParticleComponent :
		public Component
	{
	private:
		float m_maxDt;
		float m_totalDt = 0.0;
		void createParticleFor(GameEntity *entity);
	public:

		ParticleComponent(float maxDt);
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(float dt, GameEntity *entity);
		string getComponentID();
	};

}