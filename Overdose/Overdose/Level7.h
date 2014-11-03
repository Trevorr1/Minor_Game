#pragma once
#include "ILevel.h"
namespace overdose {
	class Level7 :
		public ILevel
	{
	public:
		Level7();
		Level7(GameEntity* player);
		~Level7();
		void Init();
	};
}
