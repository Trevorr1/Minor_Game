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

void GameEntity::delayedAddComponent(Component *component) {
	componentListToAdd->push_back(component);
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

void GameEntity::addComponentTemporary(Component* component){
	componentListTemporary->push_back(component);
}

std::vector<Component*>* GameEntity::getComponentList()
{
	return componentList;
}

void GameEntity::tick(float dt) {
	//Delete the component
	if (componentListToRemove->size() != 0){
		for (auto &it : *componentListToRemove){
			delete componentList->at(it); //delete WERKT, er was geen virtual destructor in Interface Component
			componentList->erase(componentList->begin() + it); // delete position in vector
			//break;
		}

		componentListToRemove->clear();
	}

	if (componentListToAdd->size() != 0){
		for (int i = 0; i < componentListToAdd->size(); i ++){
			//delete componentList->at(i); //delete object werk niet,SpeedDrug destructor wordt niet aangeroepen
			componentList->push_back(componentListToAdd->at(i)); // delete position in vector
		}

		componentListToAdd->clear();
	}

	//check for XTC DrugComponent
	if (componentListTemporary->size() != 0){
		for (int i = 0; i < componentList->size(); i++){
			if (componentListTemporary->at(0) == componentList->at(i)){
				componentList->erase(componentList->begin() + i);
			}
		}

		if (!unVulnerability){
			componentList->push_back(componentListTemporary->at(0));
			componentListTemporary->clear();
			unVulnerability = true;
		}
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


int GameEntity::getHealth() {
	if (m_health == nullptr) {
		return -1;
	}

	return *m_health;
}

void GameEntity::setHealthPointer(int* health) {
	m_health = health;
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

bool GameEntity::isJumping()
{
	return m_jumping;
}

void GameEntity::setJumping(bool isJumping)
{
	m_jumping = isJumping;
}

void GameEntity::setJumpingSpeed(float jspeed)
{
	m_jumpSpeed = jspeed;
}

float GameEntity::getJumpingSpeed()
{
	return m_jumpSpeed;
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
eFacing GameEntity::getFacing(){
	return m_Facing;
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
void GameEntity::setMovementSpeed(float movementspeed){
	this->m_movementSpeed = movementspeed;
}

void GameEntity::setFacing(eFacing facing){
	this->m_Facing = facing;
}

