#pragma once
#include "Ilevel.h"
namespace overdose {
	class GameWon : public ILevel
	{
	public:
		GameWon();
		virtual  ~GameWon();
		void Init();
		bool isGameOver();
	};

}

