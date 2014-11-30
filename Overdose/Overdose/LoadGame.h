#pragma once
#include "Ilevel.h"
using std::vector;
using std::string;
namespace overdose {
	class LoadGame : public ILevel
	{
	public:
		LoadGame();
		virtual  ~LoadGame();
		void Init();
		bool isGameOver() { return false;  }
	};

}

