#include "stdafx.h"
#include "Level1.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "EnemyMoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"
#include "DrawManager.h"
#include "ScoreboardManager.h"

using namespace overdose;

Level1::Level1()
{
	m_Camera = new Camera();

	//score
	ScoreboardManager::getInstance().startTimer();
	ScoreboardManager::getInstance().resetTimer();
	ScoreboardManager::getInstance().setName("");

	createLevel(940*2, 480); //create the level here widthx height
}

Level1::Level1(GameEntity* player)
{
	m_Player = player;
}

Level1::~Level1()
{
	delete m_Background;
}

void Level1::Init()
{
	m_Background = new Surface("assets/backgrounds/background.png");

	//std::map<eAnimationState, Animation*>* animations = new std::map<eAnimationState, Animation*>();
	//animations->insert({ Default, new Animation("assets/sprites/tiles/level1/tile_air.png", 1) });
	//DrawComponent* animation = new DrawComponent(animations);
	//animation->setAnimation(Default);//set starting animation
	//m_Tiles[0].addComponent(animation);
	//
	//animations->clear();

	//animations->insert({ Default, new Animation("assets/sprites/tiles/level1/tile_grass.png", 1) });
	//animation = new DrawComponent(animations);
	//animation->setAnimation(Default);//set starting animation
	//m_Tiles[1].addComponent(animation);

	//animations->clear();

	//animations->insert({ Default, new Animation("assets/sprites/tiles/level1/tile_ground.png", 1) });
	//animation = new DrawComponent(animations);
	//animation->setAnimation(Default);//set starting animation
	//m_Tiles[2].addComponent(animation);

	if (m_Player == nullptr)
	{
		GameEntity *player = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Player);
		m_Player = player;
	}

	m_Camera->setEntityFocus(m_Player);

	int tileMap[WORLD_SIZEY*WORLD_SIZEX] = 
	{
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
	};

	this->addEntities(m_Player);
	m_Player->setStartingPosition(100, 410 - 53 - 100); //set to world coordinates

	m_Camera->setEntityFocus(m_Player);
	//m_Camera->setTileAssets(m_Tiles);
	//m_Camera->setTileMap(tileMap, 12 * 32);


	/*
	GameEntity *entityDrugSpeed = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Drug_Speed);
	entityDrugSpeed->setStartingPosition(200, 410 - 30);
	entityDrugSpeed->setSpeedX(0);
	entityDrugSpeed->setSpeedY(0);
	this->addEntities(entityDrugSpeed);
	*/


	////GameEntity *entityDrugMarijuana = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Drug_Marijuana);
	////entityDrugMarijuana->setPosX(450);
	////entityDrugMarijuana->setPosY(410 - 60);
	////entityDrugMarijuana->setSpeedX(0);
	////entityDrugMarijuana->setSpeedY(0);
	////this->addEntities(entityDrugMarijuana);

	////GameEntity *entityDrugXTC = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Drug_XTC);
	////entityDrugXTC->setPosX(300);
	////entityDrugXTC->setPosY(410 - 30);
	////entityDrugXTC->setSpeedX(0);
	////entityDrugXTC->setSpeedY(0);
	////this->addEntities(entityDrugXTC);

	/*GameEntity *entityAdvertisement = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Advertisement_GameEntity);
	entityAdvertisement->setStartingPosition(50, 50);
	entityAdvertisement->setSpeedX(0);
	entityAdvertisement->setSpeedY(0);
	this->addEntities(entityAdvertisement);*/

	int	previousGrassWall = 0;
	int grassWall = 20;
	for (int i = 0; i < grassWall; i++){
		GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 32 * i, 410);
		this->addEntities(grass1);
	}

	previousGrassWall += grassWall;
	grassWall = 3;
	for (int i = 0; i < grassWall; i++){
		for (int j = 0; j < 4; j++){
			GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
			grass1->setStartingPosition(50 + 32 * (i + previousGrassWall), 410 - 32 * j);
			this->addEntities(grass1);
		}
	}


	previousGrassWall += grassWall;
	grassWall = 10;
	for (int i = 0; i < grassWall; i++){
		GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 32 * (i + previousGrassWall), 410);
		this->addEntities(grass1);
	}

	previousGrassWall += 1;//Empty space

	previousGrassWall += grassWall;
	grassWall = 10;
	for (int i = 0; i < grassWall; i++){
		GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 32 * (i + previousGrassWall), 410);
		this->addEntities(grass1);
	}

	GameEntity* entityCop = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	entityCop->setStartingPosition(32 + 32 * previousGrassWall, 410 - 54);
	entityCop->addComponent(new EnemyMoveComponent(32*4 + 32 * previousGrassWall, 32 * (previousGrassWall + grassWall) - 32));
	this->addEntities(entityCop);

	previousGrassWall += grassWall;
	grassWall = 10;
	for (int i = 0; i < grassWall; i++){
		GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 32 * (i + previousGrassWall), 410 - 32 * i);
		this->addEntities(grass1);
	}

	previousGrassWall += grassWall;
	GameEntity *flaggot = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Flag);
	flaggot->setStartingPosition(50 + 32 * previousGrassWall - 29, 410 - 32*13 + 17);
	this->addEntities(flaggot);


	SoundManager::getInstance().StopMusic();
	SoundManager::getInstance().PlayMusic(eMusic::Street);
	//SoundManager::getInstance()->PlaySound(eSound::Death);
}
