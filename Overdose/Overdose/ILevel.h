#pragma once
#include "stdafx.h"
#include <vector>
#include <iostream>
#include "GameEntity.h"
namespace overdose {
class ILevel
{
public:
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

};
}


