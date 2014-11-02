#pragma once
#include "ILevel.h"
namespace overdose {
	class Level6 :
		public ILevel
	{
	public:
		Level6();
		Level6(GameEntity* player);
		~Level6();
		void Init();
	};
}
