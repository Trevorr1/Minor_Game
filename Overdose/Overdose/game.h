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
		void KeyDown(unsigned int code);
		void KeyUp(unsigned int code) {}
		void MouseMove(unsigned int x, unsigned int y);
		void MouseUp(unsigned int button) {}
		void MouseDown(unsigned int button);
		~Game();
	private:
		Surface* m_Screen;
		overdose::LevelManager* m_LevelManager;
	};
