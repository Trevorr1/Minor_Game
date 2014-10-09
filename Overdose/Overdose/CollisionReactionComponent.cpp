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
	if (message == Player_ATTACKING){
		isAlive = true;
	}
}

void CollisionReactionComponent::tick(GameEntity *entity) {

	if (isAlive){
		delete entity;
	}
}