#pragma once
#include "GameEntity.h"
#include <ctime>

namespace overdose {

	class Advertisement :
		public GameEntity
	{
	public:
		Advertisement();
		virtual ~Advertisement();

		void tick(float dt);

	private:
		std::clock_t timer_start;

		int timer_ms;
	};
}