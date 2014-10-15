#include "GameEntity.h"

using std::vector;
using namespace overdose;

GameEntity::GameEntity() {

}
GameEntity::GameEntity(eGameEntity entityEnum) {
	m_EntityEnum = entityEnum;
}

GameEntity::~GameEntity() {
	//delete componentList;
}



/* Add component to the list */
void GameEntity::addComponent(Component *component) {
	component->init(this);
	//componentList->push_back(component);
}

void GameEntity::removeComponent(std::string componentID)
{
	/*for (int i = 0; i < componentList->size(); i++)
	{
		if (componentList->at(i)->getComponentID() == componentID)
		{
			componentListToRemove->push_back(i);
		}
		
	}*/
	}

std::vector<Component*>* GameEntity::getComponentList()
{
	return componentList;
}

void GameEntity::tick(float dt) {
	//Delete the component
	//if (componentListToRemove->size() != 0){
	//	for (auto &it : *componentListToRemove){
	//		componentList->erase(componentList->begin() + it);
	//		//delete &it;
	//	}

	//	componentListToRemove->clear();
	//}

	////TODO delete the used drug, via DrugComponent kan het niet runtime door de tick hieronder
	//for (auto &it : *componentList) {
	//	it->tick(dt, this);
	//}
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

void GameEntity::setFlag(ComponentMessage message, GameEntity *other)
{
	printf("CollisioReaction received");
	colX = other->getPosX();
	colY = other->getPosY();
	colBoxX = colX + other->getWidth();
	colBoxY = colY + other->getHeight();
	// resolve the collisions here
	// use object to determine with what this collided
	switch (message){
	case PlayerInputComponent_ATTACK:
		printf("Attacked by player \n");
		break;
	case CollissionComponent_COLLISION_TOP:
		printf("Collided with something from the top \n");
		collidedTop = true;
		break;
	case CollissionComponent_COLLISION_BOTTOM:
		printf("Collided with something from the bottom \n");
		collidedBottom = true;
		break;
	case CollissionComponent_COLLISION_LEFT:
		printf("Collided with something from the left \n");
		collidedLeft = true;
		break;
	case CollissionComponent_COLLISION_RIGHT:
		printf("Collided with something from the right \n");
		collidedRight = true;
		break;
	case CollissionComponent_REACTION_TOP:
		printf("Reacted with something from the top \n");
		reactTop = true;
		break;
	case CollissionComponent_REACTION_BOTTOM:
		printf("Reacted with something from the bottom \n");
		reactBottom = true;
		break;
	case CollissionComponent_REACTION_LEFT:
		printf("Reacted with something from the left \n");
		reactLeft = true;
		break;
	case CollissionComponent_REACTION_RIGHT:
		printf("Reacted with something from the right \n");
		reactRight = true;
		break;
	case Player_ATTACKING:
		printf("Player_ATTACKING? \n");
		isAlive = false;
		break;
	defualt:
		// do nothing for now
		break;
	}
}

int GameEntity::getColX()
{
	return colX;
}

int GameEntity::getColY()
{
	return colY;
}

int GameEntity::getColBoxX()
{
	return colBoxX;
}

int GameEntity::getColBoxY()
{
	return colBoxY;
}

bool GameEntity::getAlive()
{
	return isAlive;
}

bool GameEntity::getCollideTop()
{
	return collidedTop;
}

bool GameEntity::getCollideBottom()
{
	return collidedBottom;
}

bool GameEntity::getCollideLeft()
{
	return collidedLeft;
}

bool GameEntity::getCollideRight()
{
	return collidedRight;
}

bool GameEntity::getReactTop()
{
	return reactTop;
}

bool GameEntity::getReactBottom()
{
	return reactBottom;
}

bool GameEntity::getReactLeft()
{
	return reactLeft;
}

bool GameEntity::getReactRight()
{
	return reactRight;
}

void GameEntity::setCollideTop(bool ctop)
{
	collidedTop = ctop;
}

void GameEntity::setCollideBottom(bool cbot)
{
	collidedBottom = cbot;
}

void GameEntity::setCollideLeft(bool cleft)
{
	collidedLeft = cleft;
}

void GameEntity::setCollideRight(bool cright)
{
	collidedRight = cright;
}

void GameEntity::setReactTop(bool rtop)
{
	reactTop = rtop;
}

void GameEntity::setReactBottom(bool rbot)
{
	reactBottom = rbot;
}

void GameEntity::setReactLeft(bool rleft)
{
	reactLeft = rleft;
}

void GameEntity::setReactRight(bool rright)
{
	reactRight = rright;
}

void GameEntity::setAllFalse()
{
	collidedTop = false;
	collidedBottom = false;
	collidedLeft = false;
	collidedRight = false;
	reactTop = false;
	reactBottom = false;
	reactLeft = false;
	reactRight = false;
}
