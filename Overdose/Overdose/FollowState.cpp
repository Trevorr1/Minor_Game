#include "FollowState.h"
#include "AIComponent.h"
#include "CloseCombatState.h"
#include "RangedAttackState.h"
#include "FleeState.h"
using namespace overdose;
FollowState::FollowState() {
	printf("Boss - FollowState\n");

}
void FollowState::handle(AIComponent *context, GameEntity *entity) {
	if (entity->getSpeedX() == 0) {
		entity->setSpeedX(110.0f);
	}

	GameEntity *player = LevelManager::getInstance().getCurrentLevel()->getPlayerEntity();

	if (player->getPosX() > entity->getPosX() && entity->getSpeedX() < 0) {
		entity->setSpeedX(entity->getSpeedX() * -1);
	}
	else if (player->getPosX() < entity->getPosX() && entity->getSpeedX() > 0) {
		entity->setSpeedX(entity->getSpeedX() * -1);
	}

	int distance = abs(player->getPosX() - entity->getPosX());
	
	int playerFeets = player->getPosY() + player->getHeight();

	if (playerFeets + 10 < entity->getPosY() && distance < 100) { // we zijn kwestbaar van boven!
		context->setState(unique_ptr < IFSMBoss > {new FleeState(entity)});
	}

	else if (distance < RANGED_MAX_DISTANCE && distance > RANGED_MIN_DISTANCE) {
		context->setState(std::unique_ptr < IFSMBoss > {new RangedAttackState });
	}
	else if (distance < CLOSECOMBAT_RAM_DISTANCE &&
		!(player->getPosY() + player->getHeight() + 10 < entity->getPosY())) { // idk maar werkt alleen met uitroepteken ervoor.
		context->setState(std::unique_ptr < IFSMBoss > {new CloseCombatState(entity) });
	}


}