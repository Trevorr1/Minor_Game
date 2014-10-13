#pragma once
#include "Ilevel.h"
namespace overdose {
	class Level1 : public ILevel
	{
	public:
		Level1();
		~Level1();
		void Init();
	private:
		std::vector<GameEntity*> *enemies;
		std::vector<GameEntity*> *collectibles;
	};

}

