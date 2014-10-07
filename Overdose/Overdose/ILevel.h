#pragma once
#include "stdafx.h"
#include <vector>
#include <iostream>
#include "GameEntity.h"
#include "surface.h"

namespace overdose {

	class ILevel
	{
	public:
		virtual void Init() = 0;
		virtual void addEntities(GameEntity entity) = 0;
		virtual GameEntity* getPlayerEntity() = 0;
		virtual void Tick(float a_DT) = 0;
		virtual void Render(Surface* surface) = 0;
	private:
		std::vector<GameEntity> *entities;
		Surface* m_background;
		GameEntity* m_player;
	};

}


