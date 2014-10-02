#pragma once
#include "stdafx.h"

using std::string;
using std::stack;
namespace overdose {
	class InputManager
	{
	protected:
		// https://wiki.libsdl.org/SDL_Keycode
		stack<string> *keyBuffer = new stack<string>();

	public:
		InputManager();
		~InputManager();

		void addKeyPress(string keyPressed);
		string getLastKeyPress();
	private:
		void clearKeyBufferButOne();
	};

}