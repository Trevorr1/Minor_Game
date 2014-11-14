#pragma once
#include "DrugComponent.h"
#include "NegativeXTCComponent.h"

namespace overdose{

	class XTCDrugComponent :
		public DrugComponent
	{
	public:
		XTCDrugComponent();
		virtual ~XTCDrugComponent();

		void init(GameEntity* entity);
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(float dt, GameEntity *entity);
		void insertNegativeEffect(GameEntity* entitty);
		void setDrugEffects();
		float getDrugSpeed_X();
		int getDrugEffectMs();

		void setVulnerability();
		void setUnvulnerability();

		std::clock_t    timer_start;
		std::string getComponentID();

		GameEntity* XTC_gameEntity;

	private:
		float previous_speedX;
		float drug_speedX;
		int drug_effect_ms;
	};
}
