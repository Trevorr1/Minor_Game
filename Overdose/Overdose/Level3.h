#pragma once
#include "ILevel.h"
namespace overdose {
	class Level3 :
		public ILevel
	{
	public:
		Level3();
		Level3(GameEntity* player);
		~Level3();
		void Init();
	};
}