#include "stdafx.h"
#include "Level1.h"
#include "PlayerInputComponent.h"
/*Test Data*/
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"

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
	GameEntity *fpsCounter = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::FPSCounter);
	this->addEntities(fpsCounter);

	GameEntity *player = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Player);
	player->setPosX(100);
	player->setPosY(410 - 53 - 100);
	this->addEntities(player);
	m_Player = player;

	GameEntity* entityCop = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Policeman);
	entityCop->setPosX(530);
	entityCop->setPosY(410-54);
	this->addEntities(entityCop);

	GameEntity *entityDrugSpeed = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Drug_Speed);
	entityDrugSpeed->setPosX(200);
	entityDrugSpeed->setPosY(410 - 30);
	entityDrugSpeed->setSpeedX(0);
	entityDrugSpeed->setSpeedY(0);
	this->addEntities(entityDrugSpeed);

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

	SoundManager::getInstance()->PlayMusic(eMusic::Street);
	SoundManager::getInstance()->PlaySound(eSound::Death);
}
