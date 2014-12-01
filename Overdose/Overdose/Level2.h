#pragma once
#include "Ilevel.h"
#include "Tile.h"

#define WORLD_SIZEX 32
#define WORLD_SIZEY 12

namespace overdose {
	class Level2 : public ILevel
	{
	public:
		Level2();
		Level2(GameEntity* player);
		virtual ~Level2();

		void Init();

	private:
		Tile m_Tiles[3];
	};

}

