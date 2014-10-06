#include "stdafx.h"
#include "Level1.h"
using namespace overdose;
Level1::Level1(void)
{
	entities = new std::vector<GameEntity>();
}


Level1::~Level1(void)
{
	delete entities;
}

void Level1::addEntities(GameEntity entities)
{
	this->entities->push_back(entities);
}
