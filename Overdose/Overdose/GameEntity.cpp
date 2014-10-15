#include "GameEntity.h"

using std::vector;
using namespace overdose;

GameEntity::GameEntity() {

}
GameEntity::GameEntity(eGameEntity entityEnum) {
	m_EntityEnum = entityEnum;
}

GameEntity::~GameEntity() {
	delete componentList;
}



/* Add component to the list */
void GameEntity::addComponent(Component *component) {
	component->init(this);
	componentList->push_back(component);
}

void GameEntity::removeComponent(std::string componentID)
{
	//for (int i = 0; i < compontentList->size(); i++)
	//{
	//	if (compontentList->at(i)->getComponentID() == componentID)
	//	{
	//		//delete compontentList->at(i);
	//		compontentList->erase(compontentList->begin() +i);
	//		//break;
	//	}
	//}


	vector <Component*>::iterator deleteIterator = compontentList->begin();
	for (int i = 0; i < compontentList->size(); i++)
	{
		if (componentList->at(i)->getComponentID() == componentID)
		{
			//deleteIterator = compontentList->erase(deleteIterator);
			componentListToRemove->push_back(compontentList->at(i));
		}
		else{
			deleteIterator++;
		}
		
	}



	
}

void GameEntity::tick(float dt) {
	//Delete the component
	if (componentListToRemove->size() != 0){
		for (int i = 0; i < compontentList->size(); i++)
		{
			for (auto &it : *componentListToRemove) {
				if (compontentList->at(i) == it)
				{
					delete compontentList->at(i);
					compontentList->erase(compontentList->begin() + i);
				}
		}
	}
		componentListToRemove->clear();
}

	//TODO delete the used drug, via DrugComponent kan het niet runtime door de tick hieronder
	for (auto &it : *compontentList) {
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

