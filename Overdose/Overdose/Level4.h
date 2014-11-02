#pragma once
#include "ILevel.h"
namespace overdose {
	class Level4 :
		public ILevel
	{
	public:
		Level4();
		Level4(GameEntity* player);
		~Level4();
		void Init();
	};
}
