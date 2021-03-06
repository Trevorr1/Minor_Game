#include "GameEntity.h"

using std::vector;
using namespace overdose;

GameEntity::GameEntity() {

}
GameEntity::GameEntity(eGameEntity entityEnum) {
	m_EntityEnum = entityEnum;
}

GameEntity::GameEntity(eGameEntity entityEnum, Component *component, ...) : m_EntityEnum(entityEnum) {
	va_list arguments;
	for (va_start(arguments, component); component != FinalComponent; component = va_arg(arguments, Component *)) {
		component->init(this);
		componentList->push_back(component);

	}
	va_end(arguments);
	delete arguments;

}

GameEntity::~GameEntity() {
	componentListToRemove->clear();
	delete componentListToRemove; //bevat alleen primitives

	clearList<Component>(componentList);
	clearList<Component>(componentListTemporary);
	clearList<Component>(componentListToAdd);
}



/* Add component to the list */
void GameEntity::addComponent(Component *component) {
	if (component != nullptr) {
		component->init(this);
		componentList->push_back(component);
	}
}

void GameEntity::delayedAddComponent(Component *component) {
	componentListToAdd->push_back(component);
}

void GameEntity::removeComponent(std::string componentID)
{
	for (unsigned int i = 0; i < componentList->size(); i++)
	{
		if (componentList->at(i)->getComponentID() == componentID && !IsComponentScheduledForRemoval(i))
		{
			componentListToRemove->push_back(i);
		}
		
	}
}

bool GameEntity::IsComponentScheduledForRemoval(int id) {
	return std::find(componentListToRemove->begin(), componentListToRemove->end(), id) != componentListToRemove->end();
}

void GameEntity::addComponentTemporary(Component* component){
	componentListTemporary->push_back(component);
}

std::vector<Component*>* GameEntity::getComponentList()
{
	return componentList;
}

void GameEntity::tick(float dt) {
	/*if (m_EntityEnum == Player){
		std::cout << speedX << std::endl;
	}*/
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
			addComponent(componentListToAdd->at(i)); // delete position in vector
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

void GameEntity::setHealth(int health) {
	if (m_health != nullptr && getHealth() <= 6) {
		*m_health = health;
	}

	
	// Hacky fix for bug - make sure your health never exceeds 6
	if (getHealth() >= 6) {
		*m_health = 6;
	}
}

void GameEntity::broadcast(Component *subject, ComponentMessage message, GameEntity *object)
{
	if (object == nullptr) {
		throw std::invalid_argument("A component broadcasted a nullptr as Object parameter which is bad, mmkay?.");
	}
	for (auto &it : *componentList) {
		it->receive(subject, message, object);
	}
}

void GameEntity::broadcastBatchMessages(Component *subject, std::map<ComponentMessage, GameEntity*> messages)
{
	for (auto &it : *componentList) {
		it->receiveMessageBatch(subject, messages);
	}
}


bool GameEntity::isJumping()
{
	return m_jumping;
}

bool GameEntity::isFalling()
{
	return m_falling;
}

void GameEntity::setJumping(bool isJumping)
{
	m_jumping = isJumping;
}

void GameEntity::setFalling(bool isFalling)
{
	m_falling = isFalling;
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

void GameEntity::setStartingPosition(float x, float y){
	posX = startPosX = x;
	posY = startPosY = y;
}
void GameEntity::respawn(){
	posX = startPosX;
	posY = startPosY;
	speedX = 0.0f;
	speedY = 0.0f;
}

void GameEntity::setMovementSpeed(float movementspeed){
	m_movementSpeed = movementspeed;
}

void GameEntity::setFacing(eFacing facing){
	this->m_Facing = facing;
}

