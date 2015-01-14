#pragma once
#include "Ilevel.h"
#include "Tile.h"
#include <time.h>
namespace overdose {
	class Level4 : public ILevel
	{
	private:
		time_t m_sirenStart = -1;
	public:
		Level4();
		Level4(GameEntity* player);
		virtual ~Level4();

		void Init();
		bool isGameWon();
	};

}

