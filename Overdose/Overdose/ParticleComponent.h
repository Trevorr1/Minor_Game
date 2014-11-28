#pragma once
#include "Component.h"
#include "LevelManager.h"
#include "MoveComponent.h"
#include "DrawComponent.h"
#include "KillSwitchComponent.h"
#include "gravityComponent.h"
#define PARTICLES_FOREVER -1

using std::string;
namespace overdose{
	enum ParticleType {
		SmileyFace,
		Blood,
		RedLum
	};

	class ParticleComponent :
		public Component
	{
	private:
		float m_maxDt;
		float m_totalDt = 0.0;
		float m_lifetime;
		float m_selfLifetime = 0.0;
		float m_selfDestruct;
		ParticleType m_type;
		void createParticleFor(GameEntity *entity);
		char* getSpritePath();
	public:

		ParticleComponent(ParticleType type, float maxDt, float lifetime, float selfDestructIn);
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		string getComponentID();
	};

}