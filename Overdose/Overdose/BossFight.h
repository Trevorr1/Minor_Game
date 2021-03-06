#pragma once
#include "Ilevel.h"
#include "Tile.h"

#define WORLD_SIZEX 32
#define WORLD_SIZEY 12

namespace overdose {
	class BossFight : public ILevel
	{
	public:
		BossFight();
		BossFight(GameEntity* player);
		virtual ~BossFight();

		void Init();

	private:
		Tile m_Tiles[3];
	};

}

