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
	GameEntity *entity = new GameEntity();
	Component *comp = new MoveComponent();
	entity->setPosX(100);
	entity->setPosY(50);
	entity->addComponent(*comp);
	this->addEntities(*entity);
	player = entity;

	GameEntity *enemy = new GameEntity();
	enemy->setPosX(100);
	enemy->setPosY(50);
	enemy->addComponent(*comp);
	this->addEntities(*enemy);
}

GameEntity Level1::getPlayerEntity()
{
	return *player;
}

std::vector<GameEntity>* Level1::getEntities()
{
	return entities;
}

void Level1::tick(double dt)
{
	for (int i = 0; i < entities->size(); i++)
	{
		entities->at(i).tick();
	}
}