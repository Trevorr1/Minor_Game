#pragma once
#include "Ilevel.h"
#include "Tile.h"

#define WORLD_SIZEX 32
#define WORLD_SIZEY 12

namespace overdose {
	class Level1 : public ILevel
	{
	public:
		Level1();
		Level1(GameEntity* player);
		virtual ~Level1();

		void Tick(float a_DT);
		void Init();

	private:
		
		Tile m_Tiles[3];
	};

}

