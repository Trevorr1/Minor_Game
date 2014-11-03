#pragma once
#include "ILevel.h"
namespace overdose {
	class Level10 :
		public ILevel
	{
	public:
		Level10();
		Level10(GameEntity* player);
		~Level10();
		void Init();
	};
}
