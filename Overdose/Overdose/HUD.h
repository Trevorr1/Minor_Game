#pragma once
#include <vector>
#include "GameEntity.h"
#include "DrawComponent.h"
#include "HealthHearts.h"

namespace overdose {
	class HUD :
		public GameEntity
	{
	public:
		HUD();
		HUD(GameEntity* entity);
		virtual ~HUD();

		void tick(float dt);
	private:
		GameEntity* m_Entity;
		DrawComponent* m_DrawComponent;
		int m_DrugEffect_ms;
		int m_CurrentEffect_ms;
		int m_MaxHealth;
		int m_CurrentHealth;
		std::vector<HealthHearts*> m_Hearts;
	};

} // namespace overdose