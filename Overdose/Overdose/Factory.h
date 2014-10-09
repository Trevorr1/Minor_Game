#pragma once
#include "stdafx.h"
#include "Enum.h"
#include "GameEntity.h"

namespace overdose {
	class GameEntityFactory
	{
	private:
		static GameEntityFactory* _instance;
		GameEntityFactory();
	public:
		static GameEntityFactory* getInstance();
		GameEntity* getGameEntity(eGameEntity entityEnum);
		~GameEntityFactory();
	};
}
