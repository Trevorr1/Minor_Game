#pragma once
#include "Ilevel.h"
namespace overdose {
	class Level2 : 
		public ILevel
	{
	public:
		Level2();
		Level2(GameEntity* player);
		virtual ~Level2();
		void Init();
	};

}

