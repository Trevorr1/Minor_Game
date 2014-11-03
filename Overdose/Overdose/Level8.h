#pragma once
#include "ILevel.h"
namespace overdose {
	class Level8 :
		public ILevel
	{
	public:
		Level8();
		Level8(GameEntity* player);
		~Level8();
		void Init();
	};
}
