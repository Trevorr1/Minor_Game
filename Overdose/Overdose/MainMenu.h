#pragma once
#include "Ilevel.h"
namespace overdose {
	class MainMenu : public ILevel
	{
	public:
		MainMenu();
		virtual  ~MainMenu();
		void Init();
		bool isGameOver();
	};

}

