#include "stdafx.h"
#include "ILevel.h"
#include "GameEntityFactory.h"

using namespace overdose;

ILevel::ILevel()
{

	m_WorldSizeX = 940;
	m_WorldSizeY = 480;
	GameEntity *fpsCounter = GameEntityFactory::getInstance().getGameEntity(eGameEntity::FPSCounter);
	this->addEntities(fpsCounter);

	createLevel(m_WorldSizeX, m_WorldSizeY); //maybe let this return the created surface?
}

void ILevel::addEntities(GameEntity* entities)
{
	this->entities->push_back(entities);


}

void ILevel::scheduleEntityForInsertion(GameEntity* entity) {
	insertEntityBuffer->push_back(entity);
}



void ILevel::removeEntity(GameEntity* entity) 
{
	for (auto &it : *entities) 
	{
		if (entity == it) 
		{
			it = nullptr;
			delete entity;
		}
	}
}


GameEntity* ILevel::getPlayerEntity()
{
	return m_Player;
}

//Steals the gameEntity, meaning removing it from this level
GameEntity* ILevel::takePlayerEntity()
{
	GameEntity* player = getPlayerEntity();
	player->setSpeedX(0.0f);
	player->setSpeedY(0.0f);
	player->setMovementSpeed(190.0f); /* HARDCODED: Must fix this */

	if (player != nullptr)
	{
		std::vector<GameEntity*>::iterator position = std::find(entities->begin(), entities->end(), player);
		if (position != entities->end()){
			entities->erase(position);
		}

	}

	removeDrugComponents(player);

	return player;
}

void ILevel::setPlayerEntity(GameEntity* player)
{
	m_Player = player;
}


std::vector<GameEntity*>* ILevel::getEntities()
{
	return entities;
}

void ILevel::removeDrugComponents(GameEntity* player){
	for (auto component : *player->getComponentList()){
		if (component->getComponentID().find("DrugComponent") != std::string::npos || component->getComponentID().find("Negative") != std::string::npos){
			player->removeComponent(component->getComponentID());
		}
	}
}

//std::vector<GameEntity*>* ILevel::getCollectibles(){
//	return collectibles;
//}
//
//std::vector<GameEntity*>* ILevel::getEnemies(){
//	return enemies;
//}

void ILevel::DrawBackground()
{
	int levelWidth = m_WorldSizeX;
	int position = 0;
	int positionSteps = m_Background->GetWidth();
	while (levelWidth > 0){
		m_Background->CopyTo(DrawManager::getInstance().getLevelSurface(), position, 0); //copy to origin
		position += positionSteps;
		levelWidth -= positionSteps;
	}
}

void ILevel::Tick(float dt)
{
	DrawBackground();

	// gebufferde entities eerst
	for (auto &it : *insertEntityBuffer) {
		entities->push_back(it);
	}

	insertEntityBuffer->clear();
	
	auto toRemove = std::remove_if(entities->begin(), entities->end(), [](GameEntity* p) {
		if (p->isScheduledForRemoval() && p->getEnum() != eGameEntity::Player) {
			delete p;
			return true;
		}
		return false;
	});

	entities->erase(toRemove, entities->end());

	for (auto &it : *entities) 
	{
		it->tick(dt);
	}
	if (m_Camera != nullptr)
		m_Camera->Tick(dt);

	if (hud != nullptr){
		hud->tick(dt);
	}

	//Create Head-up Display if player exists
	if (m_Player != nullptr && hud == nullptr){
		hud = new HUD(m_Player, 20.0f, 20.0f);
	}
}

bool ILevel::isGameOver() 
{
	return m_Player->isScheduledForRemoval();
}

void ILevel::createLevel(int width, int height)
{
	DrawManager::getInstance().createLevelSurface(width, height);
}

bool ILevel::isGameWon() 
{
	return m_IsGameWon;
}

void ILevel::setGameWon()
{
	m_IsGameWon = true;
}

bool ILevel::isReloadLevel() 
{
	return m_IsReloadLevel;
}

void ILevel::setReloadLevel()
{
	m_IsReloadLevel = true;
}

ILevel::~ILevel() 
{
	printf("Level unloaded from the game.\n");
	delete m_Camera;
	//delete m_Player;

	while (!entities->empty()) 
	{
		delete entities->back();
		entities->pop_back();
	}

	delete entities;

	while (!insertEntityBuffer->empty()) {
		delete insertEntityBuffer->back();
		insertEntityBuffer->pop_back();
	}

	delete insertEntityBuffer;

	delete hud;

	Surface::flushImageCache();
}



void ILevel::addGrassBlock(int xOffset, int yOffset, int width, int height)
{
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			GameEntity* grass = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
			grass->setStartingPosition(xOffset + 32 * (i), yOffset - 32 * j);
			this->addEntities(grass);
		}
	}
}