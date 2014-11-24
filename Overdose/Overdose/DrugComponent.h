#pragma once
#include "Component.h"
#include <ctime>
#include <iostream>
#include "surface.h"
#include "LevelManager.h"


namespace overdose {
	class DrugComponent :
		public Component
	{
	public:
		DrugComponent();
		virtual ~DrugComponent();

		void init(GameEntity *entity);
		virtual void receive(Component *subject, ComponentMessage message, GameEntity *object);
		virtual void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		virtual void tick(float dt, GameEntity *entity);
		ILevel* getLevel(){ return level; };
		Surface* getSurface(){ return surface; };

		float getPrevious_SpeedX();
		int getTimer_Start();

		int getStartTime() { return timer_start; }

		virtual float getDrugSpeed_X();
		virtual int getDrugEffectMs();

		std::string getComponentID();

	private:
		GameEntity* entity;
		float previous_speedX;
		std::clock_t timer_start;
		virtual void insertNegativeEffect(GameEntity* entity);

		ILevel* level;
		Surface* surface;
	};
}

