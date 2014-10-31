#include "stdafx.h"
#include "Level1.h"
#include "PlayerInputComponent.h"
/*Test Data*/
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
	/*Test Data*/
	GameEntity *fpsCounter = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::FPSCounter);
	this->addEntities(fpsCounter);

	GameEntity *player = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Player);
	player->setPosX(100);
	player->setPosY(410 - 53 - 100);
	this->addEntities(player);
	m_Player = player;

	GameEntity* entityCop = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Policeman);
	entityCop->setPosX(500);
	entityCop->setPosY(410-54);
	this->addEntities(entityCop);

	GameEntity *entityDrugSpeed = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Drug_Speed);
	entityDrugSpeed->setPosX(200);
	entityDrugSpeed->setPosY(410 - 30);
	entityDrugSpeed->setSpeedX(0);
	entityDrugSpeed->setSpeedY(0);
	this->addEntities(entityDrugSpeed);


	//GameEntity *entityDrugMarijuana = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Drug_Marijuana);
	//entityDrugMarijuana->setPosX(450);
	//entityDrugMarijuana->setPosY(410 - 60);
	//entityDrugMarijuana->setSpeedX(0);
	//entityDrugMarijuana->setSpeedY(0);
	//this->addEntities(entityDrugMarijuana);

	//GameEntity *entityDrugXTC = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Drug_XTC);
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
		GameEntity* grass1 = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Grass);
		grass1->setPosX(50 + 32 * i);
		grass1->setPosY(410);
		this->addEntities(grass1);
	}


	GameEntity *flaggot = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Flag);
	flaggot->setPosX(700);
	flaggot->setPosY(410 - 112);
	this->addEntities(flaggot);


	SoundManager::getInstance().StopMusic();
	SoundManager::getInstance().PlayMusic(eMusic::Street);
	//SoundManager::getInstance()->PlaySound(eSound::Death);
}
