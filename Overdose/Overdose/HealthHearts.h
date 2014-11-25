#pragma once
#include "HUDEntity.h"
#include "DrawComponent.h"

namespace overdose {

	class HealthHearts :
		public HUDEntity
	{
		enum eHeartState { Heart_Full, Heart_Empty };
	public:
		HealthHearts(int x, int y);
		virtual ~HealthHearts();

		void setState(eHeartState state) { m_State = state; }
		eHeartState getState() { return m_State; }

		void tick(float dt);
	private:
		eHeartState m_State;
	};
} // namespace overdose