#include "GameEntity.h"

using std::vector;
using namespace overdose;

vector<Component*> *compontentList = new vector<Component*>();


/* Add component to the list */
void GameEntity::addComponent(Component &component) {

	compontentList->push_back(&component);
}

void GameEntity::tick() {
	for (vector<Component*>::iterator it = compontentList->begin(); it != compontentList->end(); it++) {
		Component *component = *it;
		component->tick(this);
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

GameEntity::GameEntity() {}

GameEntity::GameEntity(eGameEntity entityEnum) {
	m_EntityEnum = entityEnum;
}

void GameEntity::broadcast(Component *subject, int message, GameEntity *object) {
	for (vector<Component*>::iterator it = compontentList->begin(); it != compontentList->end(); it++) {
		Component *component = *it;
		component->receive(subject, message, object);
	}
}

GameEntity::~GameEntity() {
	delete compontentList;
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

void GameEntity::setCollided() {
	isAlive = false;
}
