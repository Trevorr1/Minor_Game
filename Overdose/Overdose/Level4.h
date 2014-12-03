#pragma once
#include "Ilevel.h"
#include "Tile.h"

#define WORLD_SIZEX 32
#define WORLD_SIZEY 12

namespace overdose {
	class Level4 : public ILevel
	{
	public:
		Level4();
		Level4(GameEntity* player);
		virtual ~Level4();

		void Init();

	private:
		Tile m_Tiles[3];
	};

}

