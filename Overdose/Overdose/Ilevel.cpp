#include "stdafx.h"
#include "ILevel.h"
#include "GameEntityFactory.h"

using namespace overdose;

ILevel::ILevel()
{
	GameEntity *fpsCounter = GameEntityFactory::getInstance().getGameEntity(eGameEntity::FPSCounter);
	this->addEntities(fpsCounter);

	createLevel(940, 480); //maybe let this return the created surface?
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
	m_Background->CopyTo(DrawManager::getInstance().getLevelSurface(), 0, 0); //copy to origin
	m_Background->CopyTo(DrawManager::getInstance().getLevelSurface(), 940, 0); //recopy to extend the level
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

	m_Camera->Tick(dt);
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


}