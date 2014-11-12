#pragma once
#include "DrugComponent.h"
#include "NegativeMarijuanaComponent.h"

namespace overdose {

	class MarijuanaComponent :
		public DrugComponent
	{
	public:
		MarijuanaComponent();
		virtual ~MarijuanaComponent();

		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(float dt, GameEntity *entity);
		void insertNegativeEffect(GameEntity* entitty);
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
