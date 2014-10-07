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
	ILevel(void);
	~ILevel(void);
	void Init();
	void addEntities(GameEntity entity);
	GameEntity getPlayerEntity(void);
	std::vector<GameEntity> *getEntities();
	void tick(double dt);
private:
	std::vector<GameEntity> *entities;
	GameEntity *player;
		Surface* m_background;
		GameEntity* m_player;
	};

}


