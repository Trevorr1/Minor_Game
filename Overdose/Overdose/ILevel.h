#pragma once
#include "stdafx.h"
#include <vector>

#include "GameEntity.h"
#include "Camera.h"
#include "surface.h"
#include "DrawManager.h"
#include "ScheduleForRemovalFlag.h"
#include "HUD.h"

#define SCREEN_SIZEX 12
#define SCREEN_SIZEY 10

namespace overdose {

	class ILevel
	{
	public:
		ILevel();
		virtual ~ILevel();

		virtual void Init() = 0;
		virtual void addEntities(GameEntity* entity);

		void scheduleEntityForInsertion(GameEntity *entity);

		virtual GameEntity* getPlayerEntity();
		virtual GameEntity* takePlayerEntity();
		void ILevel::setPlayerEntity(GameEntity* player);

		void removeDrugComponents(GameEntity* player);
		void removeEntity(GameEntity* entity);
		virtual std::vector<GameEntity*>* getEntities();
		Surface* getSurface(){ return m_Background; };
		Camera* getCamera(){ return m_Camera; };

		virtual void Tick(float a_DT);

		virtual void createLevel(int width, int height);

		virtual bool isGameOver();
		virtual bool isGameWon();
		void setGameWon();
		bool isReloadLevel();
		void setReloadLevel();
	protected:
		std::vector<GameEntity*> *entities = new std::vector < GameEntity* > ;

		unsigned int m_WorldSizeX;
		unsigned int m_WorldSizeY;

		std::vector<GameEntity*> *insertEntityBuffer = new std::vector < GameEntity* > ;
		virtual void DrawBackground();

		Surface* m_Background;
		GameEntity* m_Player = nullptr;
		HUD* hud = nullptr;
		GameEntity* m_FpsCounter = nullptr;
		Camera* m_Camera;


		bool m_IsGameWon = false;
		bool m_IsReloadLevel = false;

		void loadXML(int level);

	};
}


