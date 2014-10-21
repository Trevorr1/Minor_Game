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
	};
}
