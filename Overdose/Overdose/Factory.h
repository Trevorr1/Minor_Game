#pragma once

#include "Enum.h"
#include "GameEntity.h"

namespace overdose {
	class Factory
	{
	private:
		static Factory* _instance;
		Factory();
	public:
		static Factory* getInstance();
		GameEntity* getGameEntity(eGameEntity entityEnum);
		~Factory();
	};
}
