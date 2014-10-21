#pragma once
#include "Ilevel.h"
namespace overdose {
	class GameOver : public ILevel
	{
	public:
		GameOver();
		virtual  ~GameOver();
		void Init();
	private:
		std::vector<GameEntity*> *enemies;
		std::vector<GameEntity*> *collectibles;
	};

}

