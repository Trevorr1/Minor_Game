#pragma once
#include "stdafx.h"

using std::stack;
namespace overdose {
	struct MouseClick {
		int x, y, button;
	};

	class InputManager
	{
	private:
		static InputManager* _instance;
		InputManager();
		virtual ~InputManager();

	protected:
		// https://wiki.libsdl.org/SDL_Keycode
		stack<int> *keyBuffer = new stack<int>();

		stack<MouseClick> *mouseBuffer = new stack<MouseClick>();

	public:
		
		void addKeyPress(unsigned int keyPressed);
		int getLastKeyPress();
		void clearKeyBuffer();

		void addMouseClick(MouseClick click);
		MouseClick getLastMouseClick();
		void clearMouseBuffer();


		static InputManager* getInstance();

		
	private:
		void clearKeyBufferButOne();
		void clearMouseBufferButOne();
	};

}