#pragma once
#include "ILevel.h"
namespace overdose {
	class Level9 :
		public ILevel
	{
	public:
		Level9();
		Level9(GameEntity* player);
		~Level9();
		void Init();
	};
}
