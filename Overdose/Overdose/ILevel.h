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
	void addEntities(GameEntity entity);
private:
	std::vector<GameEntity> *entities;

};
}


