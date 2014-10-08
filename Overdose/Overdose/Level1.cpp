#include "stdafx.h"
#include "Level1.h"
#include "MoveComponent.h"
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

void Level1::Init()
{
	GameEntity *entity = new GameEntity(Ross);
	Component *comp = new MoveComponent();
	entity->setPosX(100);
	entity->setPosY(50);
	entity->addComponent(*comp);
	this->addEntities(*entity);
}
