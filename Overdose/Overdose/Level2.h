#pragma once
#include "Ilevel.h"
namespace overdose {
	class Level2 : public ILevel
	{
	public:
		Level2();
		virtual ~Level2();
		void Init();
	private:
		std::vector<GameEntity*> *enemies;
		std::vector<GameEntity*> *collectibles;
	};

}

