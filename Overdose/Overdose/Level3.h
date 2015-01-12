#pragma once
#include "Ilevel.h"
#include "Tile.h"

namespace overdose {
	class Level3 : public ILevel
	{
	public:
		Level3();
		Level3(GameEntity* player);
		virtual ~Level3();

		void Init();

	private:
	};

}

