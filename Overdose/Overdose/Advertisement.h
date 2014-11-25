#pragma once
#include "GameEntity.h"
#include "Enum.h"
#include <ctime>

namespace overdose {

	class Advertisement :
		public GameEntity
	{
	public:
		Advertisement();
		Advertisement(eGameEntity entityEnum, GameEntity* closeButton);
		virtual ~Advertisement();

		void init();
		void tick(float dt);

		void setStartingPosition(float x, float y);

	private:
		std::clock_t timer_start;

		int timer_ms;
		GameEntity* closeButton;
	};
}