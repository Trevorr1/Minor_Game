#pragma once
#include "stdafx.h"
#include <map>
#include <iostream>
#include "Component.h"
#include "InputManager.h"
#include "DrawManager.h"

namespace overdose{
	class TextBoxInputComponent : public Component
	{
	public:
		TextBoxInputComponent();
		virtual ~TextBoxInputComponent();

		std::string getComponentID();

		void tick(float dt, GameEntity *entity);
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);

	private:
		void Init();
		bool clicked = false;
		bool text_typed = false;
		std::string toWrite = "";
		void setPos(int x, int y);
		int x, y;
		std::map<int, std::string>* sdlKeyCodes = new std::map<int, std::string>();
	};
}