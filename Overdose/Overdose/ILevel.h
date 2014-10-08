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
	virtual void addEntities(GameEntity* entity) = 0;
	virtual GameEntity* getPlayerEntity() = 0;
	virtual std::vector<GameEntity> *getEntities() = 0;
	virtual void Tick(float a_DT) = 0;
	virtual void Render(Surface* surface) = 0;
protected:
	std::vector<GameEntity> *entities;
	Surface* m_Background;
	GameEntity* m_Player;

};
}


