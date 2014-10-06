#pragma once
#include "stdafx.h"

using std::stack;
namespace overdose {
	class InputManager
	{
	private:
		static InputManager* _instance;
		InputManager();
		virtual ~InputManager();

	protected:
		// https://wiki.libsdl.org/SDL_Keycode
		stack<int> *keyBuffer = new stack<int>();

	public:
		

		void addKeyPress(unsigned int keyPressed);
		int getLastKeyPress();

		static InputManager* getInstance();

		void clearKeyBuffer();
	private:
		void clearKeyBufferButOne();
	};

}