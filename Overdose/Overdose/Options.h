#pragma once
#include "Ilevel.h"
#include "GameEntityFactory.h"
namespace overdose {
	class Options : public ILevel
	{
	public:
		Options();
		virtual ~Options();
		void Init();
		bool isGameOver() { return false;  }
	};
}

