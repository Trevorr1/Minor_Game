#pragma once
#include "stdafx.h"
#include <vector>
#include <iostream>
#include "GameEntity.h"
#include "surface.h"
#include "DrawManager.h"

namespace overdose {
	class ILevel
	{
	public:
		virtual void Init() = 0;
		virtual void addEntities(GameEntity* entity) = 0;
		virtual void addEnemies(GameEntity* entity) = 0;
		virtual void addCollectibles(GameEntity* entity) = 0;
		virtual GameEntity* getPlayerEntity() = 0;
		virtual std::vector<GameEntity*> *getEntities() = 0;
		virtual std::vector<GameEntity*> *getEnemies() = 0;
		virtual std::vector<GameEntity*> *getCollectibles() = 0;
		virtual void Tick(float a_DT) = 0;
	protected:
		std::vector<GameEntity*> *entities;
		std::vector<GameEntity*> *enemies;
		std::vector<GameEntity*> *collectibles;
		virtual void DrawBackground() = 0;
		Surface* m_Background;
		GameEntity* m_Player;

	};
}


