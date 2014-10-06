#include "stdafx.h"
#include "ILevel.h"
using namespace overdose;

ILevel::ILevel(void)
{
	entities = new std::vector<GameEntity>();
}


ILevel::~ILevel(void)
{
}

void ILevel::addEntities(GameEntity entities)
{
	//this->entities->insert(entities);
	this->entities->push_back(entities);
	//(*this->entities)->insert(entities);
}
