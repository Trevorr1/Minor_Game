#include "stdafx.h"
#include "Level6.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"

using namespace overdose;

Level6::Level6()
{
}

Level6::Level6(GameEntity* player)
{
	m_Player = player;
}

Level6::~Level6()
{
	delete m_Background;
}

void Level6::Init()
{
	m_Background = new Surface("assets/backgrounds/background.png");

	if (m_Player == nullptr){
		GameEntity *player = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Player);
		m_Player = player;
	}

	this->addEntities(m_Player);
	m_Player->setStartingPosition(100, 410 - 53 - 100);

	GameEntity *entityDrugSpeed = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Drug_Speed);
	entityDrugSpeed->setStartingPosition(200, 410 - 30);
	entityDrugSpeed->setSpeedX(0);
	entityDrugSpeed->setSpeedY(0);
	this->addEntities(entityDrugSpeed);

	int grassWall = 10;
	for (int i = 0; i < grassWall; i++){
		GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 32 * i, 410);
		this->addEntities(grass1);
	}


	//GameEntity* entityCop = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	//entityCop->setStartingPosition(750, 410 - 210 - 50);
	//this->addEntities(entityCop);

	grassWall = 24;
	for (int i = 11; i < grassWall; i++){
		GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 32 * i, 410 - 210);
		this->addEntities(grass1);
	}


	GameEntity *entityDrugSpeed2 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Drug_Speed);
	entityDrugSpeed2->setStartingPosition(50 + 32 * 5, 410 - 150);
	entityDrugSpeed2->setSpeedX(0);
	entityDrugSpeed2->setSpeedY(0);
	this->addEntities(entityDrugSpeed2);

	//platform
	grassWall = 9;
	for (int i = 5; i < grassWall; i++){
		GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 32 * i, 410 - 110);
		this->addEntities(grass1);
	}

	grassWall = 14;
	for (int i = 11; i < grassWall; i++){
		GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 32 * i, 410 - 80);
		this->addEntities(grass1);
	}
	//vertical wall
	grassWall = 4;
	for (int i = 1; i < grassWall; i++){
		GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 32 * 14, 410 - (80 + (32 * i)));
		this->addEntities(grass1);
	}

	grassWall = 22;
	for (int i = 18; i < grassWall; i++){
		GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 32 * i, 410);
		this->addEntities(grass1);
	}

	grassWall = 27;
	for (int i = 25; i < grassWall; i++){
		GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 32 * i, 410 - 100);
		this->addEntities(grass1);
	}

	GameEntity *flaggot = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Flag);
	flaggot->setStartingPosition(700, 410 - 112);
	this->addEntities(flaggot);

}