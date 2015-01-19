#pragma once
#include "Ilevel.h"
#include "Tile.h"

namespace overdose
{
	class Level9 : public ILevel
	{
	public:
		Level9();
		Level9(GameEntity* player);
		virtual ~Level9();
		void Init();
		bool isGameWon();
	private:
		time_t m_sirenStart = -1;
	};
}
