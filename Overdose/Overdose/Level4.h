#pragma once
#include "Ilevel.h"
#include "Tile.h"

namespace overdose {
	class Level4 : public ILevel
	{
	public:
		Level4();
		Level4(GameEntity* player);
		virtual ~Level4();

		void Init();

	};

}

