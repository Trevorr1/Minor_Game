#pragma once
#include "GameEntity.h"
#include "DrawComponent.h"

namespace overdose {

	class HealthHearts :
		public GameEntity
	{
	public:
		HealthHearts();
		virtual ~HealthHearts();
	private:
		DrawComponent* m_DrawComponent;
	};
} // namespace overdose