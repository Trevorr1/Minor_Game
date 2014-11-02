#include "stdafx.h"
#include "Level4.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"

using namespace overdose;

Level4::Level4()
{
	m_Background = new Surface("assets/backgrounds/background.png");
}


Level4::~Level4()
{
	delete m_Background;
}

void Level4::Init()
{

	GameEntity *player = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Player);
	player->setStartingPosition(100, 410 - 53 - 100);
	this->addEntities(player);
	m_Player = player;

	GameEntity *entityDrugSpeed = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Drug_Speed);
	entityDrugSpeed->setStartingPosition(230, 410 - 30);
	entityDrugSpeed->setSpeedX(0);
	entityDrugSpeed->setSpeedY(0);
	this->addEntities(entityDrugSpeed);


	int grassWall = 22;
	for (int i = 0; i < grassWall; i++){
		if (i > (grassWall/2 - 2) && i < (grassWall/2 + 2) || i == 4){
			continue;
		}
		GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 32 * i, 410);
		this->addEntities(grass1);
	}

	GameEntity *flaggot = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Flag);
	flaggot->setStartingPosition(700, 410 - 112);
	this->addEntities(flaggot);

}
