#pragma once
#include "stdafx.h"
#include "Component.h"
#include "DrawManager.h"
#include "InputManager.h"
#include <iostream>

namespace overdose {
	class FPSDrawComponent : public Component
	{
	private:
		int ticksOnScreen = 0;
		void calculateTicksOnScreen();
		double m_dt = 0;
		int m_ticks = 0;


	public:

		std::string getComponentID();
		void receive(Component *subject, ComponentMessage message, GameEntity *object);

		void tick(float dt, GameEntity *entity);
	};

}