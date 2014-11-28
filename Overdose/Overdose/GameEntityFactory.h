#pragma once
#include "stdafx.h"
#include "Enum.h"
#include "GameEntity.h"
#include "Advertisement.h"

namespace overdose {
	class GameEntityFactory
	{
	private:
		GameEntityFactory();
	public:
		static GameEntityFactory &getInstance();
		GameEntity* getGameEntity(eGameEntity entityEnum);
		~GameEntityFactory();
	};
}
