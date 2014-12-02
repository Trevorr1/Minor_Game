#pragma once
#include "Ilevel.h"
#include "Tile.h"

#define WORLD_SIZEX 32
#define WORLD_SIZEY 12

namespace overdose {
	class Level3 : public ILevel
	{
	public:
		Level3();
		Level3(GameEntity* player);
		virtual ~Level3();

		void Init();

	private:
		Tile m_Tiles[3];
	};

}

