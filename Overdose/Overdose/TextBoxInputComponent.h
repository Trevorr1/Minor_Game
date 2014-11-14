#pragma once
#include "stdafx.h"
#include <map>
#include <iostream>
#include "Component.h"
#include "InputManager.h"

namespace overdose{
	class TextBoxInputComponent : public Component
	{
	public:
		TextBoxInputComponent();
		virtual ~TextBoxInputComponent();

		std::string getComponentID();

		void tick(float dt, GameEntity *entity);
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
	private:
		void Init();

		std::map<int, std::string>* sdlKeyCodes = new std::map<int, std::string>();
	};
}