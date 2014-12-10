#include "FollowState.h"
#include "AIComponent.h"
#include "FlyAttackState.h"
#include "RangedAttackState.h"
using namespace overdose;

void FollowState::handle(AIComponent *context, GameEntity *entity) {
	GameEntity *player = LevelManager::getInstance().getCurrentLevel()->getPlayerEntity();

	if (player->getPosX() > entity->getPosX() && entity->getSpeedX() < 0) {
		entity->setSpeedX(entity->getSpeedX() * -1);
	}
	else if (player->getPosX() < entity->getPosX() && entity->getSpeedX() > 0) {
		entity->setSpeedX(entity->getSpeedX() * -1);
	}

	if (abs(player->getPosX() - entity->getPosX()) < RANGED_MAX_DISTANCE) {
		context->setState(std::unique_ptr < IFSMBoss > {new RangedAttackState });
	}

}