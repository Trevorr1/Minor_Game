#include "FollowState.h"
#include "AIComponent.h"
#include "CloseCombatState.h"
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

	int distance = abs(player->getPosX() - entity->getPosX());

	if (distance < RANGED_MAX_DISTANCE && distance > RANGED_MIN_DISTANCE) {
		context->setState(std::unique_ptr < IFSMBoss > {new RangedAttackState });
	}
	else if (distance < CLOSECOMBAT_RAM_DISTANCE &&
		!(player->getPosY() + player->getHeight() + 10 < entity->getPosY())) {
		context->setState(std::unique_ptr < IFSMBoss > {new CloseCombatState(entity) });
	}



}