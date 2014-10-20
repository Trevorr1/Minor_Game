#include "GameEntity.h"

using std::vector;
using namespace overdose;

GameEntity::GameEntity() {

}
GameEntity::GameEntity(eGameEntity entityEnum) {
	m_EntityEnum = entityEnum;
}

GameEntity::~GameEntity() {
	for (auto *it : *componentList) {
		delete it;
	}
	delete componentList;
}



/* Add component to the list */
void GameEntity::addComponent(Component *component) {
	component->init(this);
	componentList->push_back(component);
}

void GameEntity::removeComponent(std::string componentID)
{
	for (unsigned int i = 0; i < componentList->size(); i++)
	{
		if (componentList->at(i)->getComponentID() == componentID)
		{
			componentListToRemove->push_back(i);
		}
		
	}
}

std::vector<Component*>* GameEntity::getComponentList()
{
	return componentList;
}

void GameEntity::tick(float dt) {
	//Delete the component
	if (componentListToRemove->size() != 0){
		for (auto &it : *componentListToRemove){
			//delete componentList->at(it); //delete object werk niet,SpeedDrug destructor wordt niet aangeroepen
			componentList->erase(componentList->begin() + it); // delete position in vector

		}

		componentListToRemove->clear();
	}

	
	for (auto &it : *componentList) {
		it->tick(dt, this);
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
	for (auto &it : *componentList) {
		it->receive(subject, message, object);
	}
}

void GameEntity::scheduleForRemoval() {
	std::cout << "Entity " << m_EntityEnum << " scheduled for removal" << std::endl;
	m_scheduledForRemoval = true;
}

bool GameEntity::isScheduledForRemoval() {
	return m_scheduledForRemoval;
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

float GameEntity::getWidth(){
	return width;
}

float GameEntity::getHeight(){
	return height;
}
float GameEntity::getMovementSpeed(){
	return m_movementSpeed;
}
void GameEntity::setMovementSpeed(float movementspeed){
	this->m_movementSpeed = movementspeed;
}

void GameEntity::setWidth(float width) {
	this->width = width;
}

void GameEntity::setHeight(float height) {
	this->height = height;
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

