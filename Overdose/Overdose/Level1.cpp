#include "stdafx.h"
#include "Level1.h"
#include "MoveComponent.h"
using namespace overdose;

Level1::Level1()
{
	entities = new std::vector<GameEntity>();
	m_Background = new Surface("images/backgrounds/background.jpg");
}


Level1::~Level1()
{
	delete entities;
}

void Level1::addEntities(GameEntity entities)
{
	this->entities->push_back(entities);
}

void Level1::Init()
{
	m_Player = new GameEntity();
	Component *comp = new MoveComponent();
	m_Player->setPosX(100);
	m_Player->setPosY(50);
	m_Player->addComponent(*comp);
	this->addEntities(*m_Player);
}

void Level1::Tick(float dt){
	float speed = 1;
	m_Player->setPosX(m_Player->getPosX() + speed);
}

void Level1::Render(Surface* surface){
	m_Background->CopyTo(surface, 0, 0);


	Surface* entitySprite = new Surface("images/sprites/drugdealer.png");
	entitySprite->CopyTo(surface, m_Player->getPosX(), m_Player->getPosY());
}


GameEntity* Level1::getPlayerEntity(){
	return m_Player;
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
