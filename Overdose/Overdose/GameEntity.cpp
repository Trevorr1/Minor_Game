#include "GameEntity.h"

using std::vector;
using namespace overdose;

GameEntity::GameEntity() {

}
GameEntity::GameEntity(eGameEntity entityEnum) {
	m_EntityEnum = entityEnum;
}

GameEntity::~GameEntity() {
	delete compontentList;
}



/* Add component to the list */
void GameEntity::addComponent(Component *component) {

	compontentList->push_back(component);
}

void GameEntity::tick() {
	if (!compontentList->empty()) {
		for (auto &it : *compontentList) {
			it->tick(this);
		}
	}
}

float GameEntity::getPosition(int index)
{
	if (index == 0)
	{
		return this->posX;
	}
	else if (index == 1)
	{
		return this->posY;
	}
	else return 0;
}




void GameEntity::broadcast(Component *subject, ComponentMessage message, GameEntity *object) {
	if (!compontentList->empty()) {
		for (auto &it : *compontentList) {
			it->receive(subject, message, object);
		}
	}
}

float GameEntity::getPosX() {
	return posX;
}

float GameEntity::getPosY() {
	return posY;

}
float GameEntity::getSpeedX() {
	return speedX;
}

float GameEntity::getSpeedY() {
	return speedY;
}

int GameEntity::getWidth(){
	return width;
}

int GameEntity::getHeight(){
	return height;
}

eGameEntity GameEntity::getEnum(){
	return m_EntityEnum;
}

void GameEntity::setSpeedX(float sx) {
	speedX = sx;
}
void GameEntity::setSpeedY(float sy) {
	speedY = sy;
}
void GameEntity::setPosX(float px) {
	posX = px;
}

void GameEntity::setPosY(float py) {
	posY = py;
}

