#include "stdafx.h"
#include "Level1.h"
#include "PlayerInputComponent.h"
/*Test Data*/
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"

using namespace overdose;


/*Test Data*/
//GameEntity* entityPtr = nullptr;

Level1::Level1()
{
	entities = new std::vector<GameEntity*>();
	enemies = new std::vector<GameEntity*>();
	collectibles = new std::vector<GameEntity*>();
	m_Background = new Surface("assets/backgrounds/background.jpg");
}


Level1::~Level1()
{
	for (int i = entities->size(); i >= 0; i--)
	{
		delete entities->at(i);
	}
	delete entities;
}

void Level1::Init()
{
	/*Test Data*/
	GameEntity *entityPtr = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::FPSCounter);
	entityPtr->setSpeedY(0);
	entityPtr->setPosX(0);
	this->addEntities(entityPtr);

	GameEntity *entityPtr1 = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::DrugAddict);
	entityPtr1->setPosY(0);
	entityPtr1->setSpeedY(0);
	this->addEntities(entityPtr1);

	GameEntity* entityCop = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Policeman);
	entityCop->setPosX(100);
	entityCop->setPosY(100);
	entityCop->setSpeedY(0);
	this->addEntities(entityCop);

	GameEntity *entityDrugSpeed = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Drug_Speed);
	entityDrugSpeed->setPosX(50);
	entityDrugSpeed->setPosY(50);
	entityDrugSpeed->setSpeedX(0);
	entityDrugSpeed->setSpeedY(0);
	this->addEntities(entityDrugSpeed);
}
