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
		virtual void addEntities(GameEntity* entity);
		virtual void addEnemies(GameEntity* entity);
		virtual void addCollectibles(GameEntity* entity);
		virtual GameEntity* getPlayerEntity();
		void removeEntity(GameEntity* entity);
		virtual std::vector<GameEntity*> *getEntities();
		virtual std::vector<GameEntity*> *getEnemies();
		virtual std::vector<GameEntity*> *getCollectibles();
		virtual void Tick(float a_DT);
		virtual bool isGameOver();
		
	protected:
		std::vector<GameEntity*> *entities;
		std::vector<GameEntity*> *enemies;
		std::vector<GameEntity*> *collectibles;
		virtual void DrawBackground();
		Surface* m_Background;
		GameEntity* m_Player = nullptr;

	};
}


