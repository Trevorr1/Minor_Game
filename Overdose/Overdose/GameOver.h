#pragma once
#include "Ilevel.h"
namespace overdose {
	class GameOver : public ILevel
	{
	public:
		GameOver();
		virtual  ~GameOver();
		void Init();
		bool isGameOver();
	};

}

