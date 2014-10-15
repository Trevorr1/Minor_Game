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
	this->addEntities(entityPtr);

	GameEntity *entityPtr1 = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::DrugAddict);
	entityPtr1->setPosX(100);
	entityPtr1->setPosY(410 - 53 - 100);
	this->addEntities(entityPtr1);

	GameEntity* entityCop = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Policeman);
	entityCop->setPosX(530);
	entityCop->setPosY(410-54);
	entityCop->setSpeedX(0.1f);
	entityCop->setSpeedY(0.0f);
	this->addEntities(entityCop);

	GameEntity *entityDrugSpeed = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Drug_Speed);
	entityDrugSpeed->setPosX(300);
	entityDrugSpeed->setPosY(410 - 30);
	entityDrugSpeed->setSpeedX(0);
	entityDrugSpeed->setSpeedY(0);
	this->addEntities(entityDrugSpeed);

	int grassWall = 22;
	for (int i = 0; i < grassWall; i++){
		if (i > (grassWall/2 - 2) && i < (grassWall/2 + 2)){
			continue;
		}
		GameEntity* grass1 = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Environment);
		grass1->setPosX(50 + 32 * i);
		grass1->setPosY(410);
		this->addEntities(grass1);
	}
}
