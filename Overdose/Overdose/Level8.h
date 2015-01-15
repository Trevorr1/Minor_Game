#pragma once
#include "Ilevel.h"
#include "Tile.h"

namespace overdose
{

	class Level8 : public ILevel
	{
	private:
		time_t m_sirenStart = -1;
	public:
		Level8();
		Level8(GameEntity* player);
		virtual ~Level8();

		void Init();
		bool isGameWon();
	};
}//namespace overdose

