#pragma once
#include "Component.h"
#include <ctime>
#include <iostream>

namespace overdose {
	class DrugComponent :
		public Component
	{
	public:
		DrugComponent();
		virtual ~DrugComponent();

		virtual void receive(Component *subject, ComponentMessage message, GameEntity *object);
		virtual void tick(float dt, GameEntity *entity);

		std::clock_t    timer_start;
		std::string getComponentID();

	private:
		float previous_speedX;
	};
}

