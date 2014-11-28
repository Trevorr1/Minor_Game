#pragma once
#include "stdafx.h"
#include "SDL_scancode.h"
#include <list>
#define KEYBOARD_BUFFER_SIZE 2

typedef uint8_t Uint8;
using std::stack;
using std::list;
namespace overdose {
	struct MouseClick {
		int x, y, button;
	};

	struct MouseCoordinate {
		unsigned int x, y;
	};

	class InputManager
	{
	private:
		InputManager();
		virtual ~InputManager();

		MouseCoordinate m_currentCoordinate;

	protected:
		// https://wiki.libsdl.org/SDL_Keycode
		Uint8 *m_keystate = nullptr;
		list<Uint8*> *m_keystateBuffer = new list < Uint8* > ;
		stack<MouseClick> *m_mouseBuffer = new stack<MouseClick>();

	public:
		void setKeyStates(Uint8 *keyStates, int size);
		void addKeyPress(unsigned int keyPressed);
		bool isKeyPressed(int sdl_code);
		bool isKeyPressedOnce(int sdl_code);
		void clearKeyBuffer();

		void addMouseClick(MouseClick click);
		MouseClick getLastMouseClick();
		void clearMouseBuffer();

		void setMouseCoordinates(MouseCoordinate co) {
			m_currentCoordinate = co;
		}

		MouseCoordinate getMouseCoordinates() { return m_currentCoordinate;  }


		static InputManager &getInstance();

		
	private:
		void clearMouseBufferButOne();
	};

}