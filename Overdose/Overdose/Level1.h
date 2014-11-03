#pragma once
#include "Ilevel.h"
namespace overdose {
	class Level1 : 
		public ILevel
	{
	public:
		Level1();
		Level1(GameEntity* player);
		virtual ~Level1();
		void Init();
	};

}

