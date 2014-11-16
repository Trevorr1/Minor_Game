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

		double m_dt = 0;
		int m_ticks = 0;
		int m_fps = 60;

		bool draw = false;
		int drawTimer = 0;


	public:

		std::string getComponentID();
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);

		void tick(float dt, GameEntity *entity);
	};

}