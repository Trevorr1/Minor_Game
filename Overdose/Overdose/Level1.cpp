#include "stdafx.h"
#include "Level1.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"

using namespace overdose;

Level1::Level1()
{
	m_Background = new Surface("assets/backgrounds/background.png");
}


Level1::~Level1()
{
	delete m_Background;
}

void Level1::Init()
{

	GameEntity *player = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Player);
	player->setStartingPosition(100, 410 - 53 - 100);
	this->addEntities(player);
	m_Player = player;

	GameEntity* entityCop = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	entityCop->setStartingPosition(500, 410 - 54);
	this->addEntities(entityCop);

	GameEntity *entityDrugSpeed = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Drug_Speed);
	entityDrugSpeed->setStartingPosition(200, 410 - 30);
	entityDrugSpeed->setSpeedX(0);
	entityDrugSpeed->setSpeedY(0);
	this->addEntities(entityDrugSpeed);


	//GameEntity *entityDrugMarijuana = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Drug_Marijuana);
	//entityDrugMarijuana->setPosX(450);
	//entityDrugMarijuana->setPosY(410 - 60);
	//entityDrugMarijuana->setSpeedX(0);
	//entityDrugMarijuana->setSpeedY(0);
	//this->addEntities(entityDrugMarijuana);

	//GameEntity *entityDrugXTC = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Drug_XTC);
	//entityDrugXTC->setPosX(300);
	//entityDrugXTC->setPosY(410 - 30);
	//entityDrugXTC->setSpeedX(0);
	//entityDrugXTC->setSpeedY(0);
	//this->addEntities(entityDrugXTC);

	int grassWall = 22;
	for (int i = 0; i < grassWall; i++){
		/*if (i > (grassWall/2 - 2) && i < (grassWall/2 + 2)){
			continue;
		}*/
		GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 32 * i, 410);
		this->addEntities(grass1);
	}


	GameEntity *flaggot = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Flag);
	flaggot->setStartingPosition(700, 410 - 112);
	this->addEntities(flaggot);


	SoundManager::getInstance().StopMusic();
	SoundManager::getInstance().PlayMusic(eMusic::Street);
	//SoundManager::getInstance()->PlaySound(eSound::Death);
}
