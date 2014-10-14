#pragma once
#include "Ilevel.h"
namespace overdose {
	class MainMenu : public ILevel
	{
	public:
		MainMenu();
		virtual  ~MainMenu();
		void Init();
	private:
		std::vector<GameEntity*> *enemies;
		std::vector<GameEntity*> *collectibles;
	};

}

