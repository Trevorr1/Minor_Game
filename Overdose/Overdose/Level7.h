#pragma once
#include "Ilevel.h"
#include "Tile.h"

namespace overdose {
	class Level7 : public ILevel
	{
	public:
		Level7();
		Level7(GameEntity* player);
		virtual ~Level7();

		void Init();

	private:
	};

}

