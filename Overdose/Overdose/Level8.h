#pragma once
#include "Ilevel.h"
#include "Tile.h"

namespace overdose
{

	class Level8 : public ILevel
	{
	public:
		Level8();
		Level8(GameEntity* player);
		virtual ~Level8();

		void Init();
	};
}//namespace overdose

