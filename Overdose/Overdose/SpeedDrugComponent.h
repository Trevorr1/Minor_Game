#pragma once
#include "DrugComponent.h"
//#include <ctime>
//#include <iostream>


namespace overdose {

	class SpeedDrugComponent :
		public DrugComponent
	{
	public:
		SpeedDrugComponent();
		virtual ~SpeedDrugComponent();

		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		void setDrugEffects();
		float getDrugSpeed_X();
		int getDrugEffectMs();

		std::clock_t    timer_start;
		std::string getComponentID();

	private:
		float previous_speedX;
		float drug_speedX;

		int drug_effect_ms;
		int negative_drug_effect_ms;

		std::vector<GameEntity*>* entityForNegativeEffect;

		void insertNegativeEffect(GameEntity* entity);
	};
}

