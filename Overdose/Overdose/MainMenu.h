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
	private:
		std::vector<GameEntity*> *enemies;
		std::vector<GameEntity*> *collectibles;
	};

}

