#pragma once
#include "InputManager.h"
#include "LevelManager.h"

	class Surface;
	class Game
	{
	public:
		void SetTarget(Surface* a_Surface) { m_Screen = a_Surface; }
		void Init();
		void Tick(float a_DT);
		void KeyStates(Uint8 *keyStates, int size);
		void MouseMove(unsigned int x, unsigned int y);
		void MouseUp(unsigned int button) {}
		void MouseDown(unsigned int button);
		Game();
		~Game();
	private:
		Surface* m_Screen;
		
		unsigned int m_mouseX, m_mouseY;
	};
