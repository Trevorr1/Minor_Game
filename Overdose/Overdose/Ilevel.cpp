#include "stdafx.h"
#include "ILevel.h"
#include "GameEntityFactory.h"

using namespace overdose;

ILevel::ILevel(){
	GameEntity *fpsCounter = GameEntityFactory::getInstance().getGameEntity(eGameEntity::FPSCounter);
	this->addEntities(fpsCounter);
}

void ILevel::addEntities(GameEntity* entities)
{
	this->entities->push_back(entities);
}

//void ILevel::addEnemies(GameEntity* entities)
//{
//	this->enemies->push_back(entities);
//}
//
//void ILevel::addCollectibles(GameEntity* entities)
//{
//	this->collectibles->push_back(entities);
//}

void ILevel::removeEntity(GameEntity* entity) {
	
	for (auto &it : *entities) {
		if (entity == it) {
			it = nullptr;
			delete entity;
		}
	}
}


GameEntity* ILevel::getPlayerEntity(){
	return m_Player;
}

std::vector<GameEntity*>* ILevel::getEntities(){
	return entities;
}

//std::vector<GameEntity*>* ILevel::getCollectibles(){
//	return collectibles;
//}
//
//std::vector<GameEntity*>* ILevel::getEnemies(){
//	return enemies;
//}

void ILevel::DrawBackground(){
	m_Background->CopyTo(DrawManager::getInstance().getSurface(), 0, 0);
}

void ILevel::Tick(float dt){

	DrawBackground();


	auto toRemove = std::remove_if(entities->begin(), entities->end(), [](GameEntity* p) {
		if (p->isScheduledForRemoval() && p->getEnum() != eGameEntity::Player) {
		
			delete p;
			return true;
		}
		return false;
	});

	entities->erase(toRemove, entities->end());

	for (auto &it : *entities) {
		it->tick(dt);
	}
}

bool ILevel::isGameOver() {
	return m_Player->isScheduledForRemoval();
}
bool ILevel::isGameWon() {
	return m_IsGameWon;
}
void ILevel::setGameWon(){
	m_IsGameWon = true;
}


ILevel::~ILevel() {
	printf("Level unloaded from the game.\n");
	//delete m_Player;

	while (!entities->empty()) {
		delete entities->back();
		entities->pop_back();
	}

	delete entities;

}