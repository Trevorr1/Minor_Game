#pragma once
#include "Component.h"
#include "LevelManager.h"
#include "MoveComponent.h"
#include "DrawComponent.h"
#include "KillSwitchComponent.h"
using std::string;
namespace overdose{
	enum ParticleType {
		SmileyFace
	};

	class ParticleComponent :
		public Component
	{
	private:
		float m_maxDt;
		float m_totalDt = 0.0;
		float m_lifetime;
		ParticleType m_type;
		void createParticleFor(GameEntity *entity);
		char* getSpritePath();
	public:

		ParticleComponent(ParticleType type, float maxDt, float lifetime);
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		string getComponentID();
	};

}