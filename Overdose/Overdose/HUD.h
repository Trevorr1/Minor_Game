#pragma once
#include <vector>
#include "GameEntity.h"
#include "HealthHearts.h"
#include "DrugDurationGauge.h"

namespace overdose {
	class HUD :
		public GameEntity
	{
	public:
		HUD(GameEntity* entity);
		virtual ~HUD();

		void tick(float dt);
	private:
		GameEntity* m_Entity;
		DrugDurationGauge* m_DrugGauge;
		std::vector<HealthHearts*>* m_Hearts;
		int m_DrugEffect_ms;
		int m_CurrentEffect_ms;
		int m_MaxHealth;
		int m_CurrentHealth;
	};
} // namespace overdose