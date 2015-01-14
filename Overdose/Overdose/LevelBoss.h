#pragma once
#include "Ilevel.h"
#include "Tile.h"
#include <time.h>
#define WORLD_SIZEX 32
#define WORLD_SIZEY 12

namespace overdose {
	class LevelBoss : public ILevel
	{
	public:
		LevelBoss();
		LevelBoss(GameEntity* player);
		virtual ~LevelBoss();
		bool isGameWon();

		void Init();

	private:
		GameEntity* m_Urquhart = nullptr;
		time_t m_UrquhartTimeOfDeath = -1;
	};

}

