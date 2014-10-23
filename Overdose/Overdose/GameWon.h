#pragma once
#include "Ilevel.h"
namespace overdose {
	class GameWon : public ILevel
	{
	public:
		GameWon();
		virtual  ~GameWon();
		void Init();
		bool isGameOver();
	private:
		std::vector<GameEntity*> *enemies;
		std::vector<GameEntity*> *collectibles;
	};

}

