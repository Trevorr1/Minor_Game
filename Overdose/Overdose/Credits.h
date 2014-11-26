#pragma once
#include "Ilevel.h"
namespace overdose {
	class Credits : public ILevel
	{
	public:
		Credits();
		virtual  ~Credits();
		void Init();
		bool isGameOver() { return false; };
	};

}

