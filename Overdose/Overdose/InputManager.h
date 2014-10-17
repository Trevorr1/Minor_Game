#pragma once
#include "stdafx.h"
#include "SDL_scancode.h"

typedef uint8_t Uint8;
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
		const Uint8 *m_keystates = nullptr;

		stack<MouseClick> *m_mouseBuffer = new stack<MouseClick>();

	public:
		void setKeyStates(const Uint8 *keyStates);
		void addKeyPress(unsigned int keyPressed);
		bool isKeyPressed(int sdl_code);
		void clearKeyBuffer();

		void addMouseClick(MouseClick click);
		MouseClick getLastMouseClick();
		void clearMouseBuffer();


		static InputManager* getInstance();

		
	private:
		void clearMouseBufferButOne();
	};

}