#pragma once
#include "stdafx.h"

using std::stack;
namespace overdose {
	class InputManager
	{
	protected:
		// https://wiki.libsdl.org/SDL_Keycode
		stack<int> *keyBuffer = new stack<int>();

	public:
		InputManager();
		virtual ~InputManager();

		void addKeyPress(int keyPressed);
		int getLastKeyPress();
	private:
		void clearKeyBufferButOne();
	};

}