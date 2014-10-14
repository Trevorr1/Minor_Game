#pragma once
#include "stdafx.h"
#include "Component.h"
#include "DrawManager.h"
#include "InputManager.h"

namespace overdose {
	class FPSDrawComponent : public Component
	{
	private:
		int ticksOnScreen = 0;
		void calculateTicksOnScreen();

	public:

		std::string getComponentID();
		void receive(Component *subject, ComponentMessage message, GameEntity *object);

		void tick(float dt, GameEntity *entity);
	};

}