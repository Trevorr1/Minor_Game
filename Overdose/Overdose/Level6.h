#pragma once
#include "Ilevel.h"
#include "Tile.h"

namespace overdose {
	class Level6 : public ILevel
	{
	public:
		Level6();
		Level6(GameEntity* player);
		virtual ~Level6();

		void Init();

	private:
	};

}