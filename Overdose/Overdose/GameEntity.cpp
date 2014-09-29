#include "stdafx.h"

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
		component->tick(*this);
	}
}

GameEntity::GameEntity() {


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