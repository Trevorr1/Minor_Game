#pragma once
#include "Ilevel.h"
#include "Tile.h"
#include <time.h>
#define WORLD_SIZEX 32
#define WORLD_SIZEY 12

namespace overdose {
	class Level4 : public ILevel
	{
	public:
		Level4();
		Level4(GameEntity* player);
		virtual ~Level4();
		bool isGameWon();

		void Init();

	private:
		GameEntity* m_Urquhart = nullptr;
		time_t m_UrquhartTimeOfDeath = -1;
	};

}

