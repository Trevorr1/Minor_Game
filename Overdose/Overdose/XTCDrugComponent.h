#pragma once
#include "DrugComponent.h"

namespace overdose{

	class XTCDrugComponent :
		public DrugComponent
	{
	public:
		XTCDrugComponent();
		virtual ~XTCDrugComponent();

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
