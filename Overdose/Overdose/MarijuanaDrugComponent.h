#pragma once
#include "DrugComponent.h"
#include "NegativeMarijuanaComponent.h"

namespace overdose {

	class MarijuanaDrugComponent :
		public DrugComponent
	{
	public:
		MarijuanaDrugComponent();
		virtual ~MarijuanaDrugComponent();
		void init(GameEntity *entity);
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		//void tick(float dt, GameEntity *entity);
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

		void insertParticleEffect(GameEntity* entity, double incr_particle_timer);
	};
}
