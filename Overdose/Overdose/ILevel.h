#pragma once
#include "stdafx.h"
#include <vector>
#include <iostream>
#include "GameEntity.h"
#include "surface.h"
#include "DrawManager.h"
#include "ScheduleForRemovalFlag.h"

namespace overdose {

	class ILevel
	{
	public:
		virtual void Init() = 0;
		virtual void addEntities(GameEntity* entity);

		virtual GameEntity* getPlayerEntity();
		void removeEntity(GameEntity* entity);
		virtual std::vector<GameEntity*> *getEntities();

		virtual void Tick(float a_DT);
		virtual bool isGameOver();
		bool isGameWon();
		void setGameWon();
		ILevel();
		virtual ~ILevel();
	protected:
		std::vector<GameEntity*> *entities = new std::vector < GameEntity* > ;

		virtual void DrawBackground();
		Surface* m_Background;
		GameEntity* m_Player = nullptr;
		bool m_IsGameWon = false;

	};
}


