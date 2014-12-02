#include "stdafx.h"
#include "Level3.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "EnemyMoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"
#include "DrawManager.h"
#include "ScoreboardManager.h"

using namespace overdose;

Level3::Level3()
{
	m_Camera = new Camera();
	createLevel(940 * 2, 480); //create the level here widthx height
}

Level3::Level3(GameEntity* player)
{
	m_Player = player;
}

Level3::~Level3()
{
	delete m_Background;
}

void Level3::Init()
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

	this->addEntities(m_Player);//(TODO: check if already is in this list??!)
	m_Player->setStartingPosition(100, 410 - 53 - 150); //set to world coordinates
	m_Camera->setEntityFocus(m_Player);

	//m_Camera->setTileAssets(m_Tiles);
	//m_Camera->setTileMap(tileMap, 12 * 32);

	//GameEntity *entityDrugSpeed = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Drug_Speed);
	//entityDrugSpeed->setStartingPosition(200, 410 - 30);
	//entityDrugSpeed->setSpeedX(0);
	//entityDrugSpeed->setSpeedY(0);
	//this->addEntities(entityDrugSpeed);

	
	int xOffset = 0;
	int blocksWidth = 0;
	
	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 5, blocksWidth, 4);
	xOffset += blocksWidth;

	blocksWidth = 5;
	addGrassBlock(32 * xOffset, 480 - 32 * 5, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 6, blocksWidth, 1);
	xOffset += blocksWidth;

	GameEntity *entityDrugSpeed1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Drug_Speed);
	entityDrugSpeed1->setStartingPosition(32 * (xOffset + 3), 480 - 32 * 8);
	entityDrugSpeed1->setSpeedX(0);
	entityDrugSpeed1->setSpeedY(0);
	this->addEntities(entityDrugSpeed1);

	blocksWidth = 6;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	addGrassBlock(32 * (xOffset + 5), 480 - 32 * 7, 1, 1);
	xOffset += blocksWidth;

	xOffset += 3;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 6, blocksWidth, 4);
	xOffset += blocksWidth;

	xOffset += 1;//whitespace

	blocksWidth = 4;
	addGrassBlock(32 * xOffset, 480 - 32 * 5, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 3;
	addGrassBlock(32 * xOffset, 480 - 32 * 6, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 3;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 3;
	addGrassBlock(32 * xOffset, 480 - 32 * 8, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 2;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 8, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 9, blocksWidth, 1);
	xOffset += blocksWidth;

	GameEntity *entityDrugSpeed = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Drug_Speed);
	entityDrugSpeed->setStartingPosition(32 * (xOffset + 1), 480 - 32 * 11);
	entityDrugSpeed->setSpeedX(0);
	entityDrugSpeed->setSpeedY(0);
	this->addEntities(entityDrugSpeed);

	blocksWidth = 5;
	addGrassBlock(32 * xOffset, 480 - 32 * 10, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 7;//whitespace

	blocksWidth = 3;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 2, blocksWidth, 6);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 2, blocksWidth, 3);
	xOffset += blocksWidth;

	GameEntity *flaggot = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Flag);
	flaggot->setStartingPosition(32 * (xOffset + 3) - 29, 480 - 32 * 2 - 111);
	this->addEntities(flaggot);

	blocksWidth = 4;
	addGrassBlock(32 * xOffset, 480 - 32 * 2, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 2, blocksWidth, 3);
	xOffset += blocksWidth;




	SoundManager::getInstance().StopMusic();
	SoundManager::getInstance().PlayMusic(eMusic::Street);
	//SoundManager::getInstance()->PlaySound(eSound::Death);
}
