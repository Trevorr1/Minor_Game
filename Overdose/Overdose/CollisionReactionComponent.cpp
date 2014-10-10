#include "CollisionReactionComponent.h"
#include "LevelManager.h"

using namespace overdose;
using namespace std;

CollisionReactionComponent::CollisionReactionComponent()
{
}


CollisionReactionComponent::~CollisionReactionComponent()
{
}

void CollisionReactionComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
	printf("CollisioReaction received");
	switch (message){
	case PlayerInputComponent_ATTACK:
		//isAlive = false;
		break;

	case CollissionComponent_COLLISION:
		isAlive = false;
		break;
	}
}

void CollisionReactionComponent::tick(float dt, GameEntity *entity) {

	if (!isAlive){
		//TODO how to delete?
		//vector<GameEntity*> *gameEntities = LevelManager::getInstance()->getCurrentLevel()->getEntities();
		//gameEntities->erase(gameEntities->begin() + 1);
		//delete entity;
	}
}