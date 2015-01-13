#pragma once
#include "Component.h"
#include <ctime>
#include <iostream>
#include "surface.h"
#include "LevelManager.h"
#include "ParticleComponent.h"


namespace overdose {
	class DrugComponent :
		public Component
	{
	public:
		DrugComponent();
		virtual ~DrugComponent();

		virtual void init(GameEntity *entity);
		virtual void receive(Component *subject, ComponentMessage message, GameEntity *object);
		virtual void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		ILevel* getLevel(){ return level; };
		Surface* getSurface(){ return surface; };

		float getPrevious_SpeedX();
		int getTimer_Start();

		virtual int getStartTime() { return timer_start; };

		virtual float getDrugSpeed_X();
		virtual int getDrugEffectMs();

		std::string getComponentID();

	private:
		GameEntity* entity;
		float previous_speedX;
		std::clock_t timer_start;
		virtual void insertNegativeEffect(GameEntity* entity);
		virtual void insertParticleEffect(GameEntity* entity, double incr_particle_timer);

		ILevel* level;
		Surface* surface;

		int timer_particle;
	};
}

