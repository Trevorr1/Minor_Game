#include "FleeState.h"
#include "AIComponent.h"
#include "RangedAttackState.h";
#include "CloseCombatState.h"
using namespace overdose;

FleeState::FleeState(GameEntity *entity) {
	m_desiredPlayerLeftDistance = entity->getPosX() - (RANGED_MIN_DISTANCE / 2); // entity = player
	m_desiredPlayerRightDistance = entity->getPosX() + (RANGED_MIN_DISTANCE / 2);
	printf("Boss - FleeState\n");
}

void FleeState::handle(AIComponent *context, GameEntity *entity) {
	GameEntity *player = LevelManager::getInstance().getCurrentLevel()->getPlayerEntity();

	int playerFeets = player->getPosY() + player->getHeight();
	int distance = abs(player->getPosX() - entity->getPosX());

	if (entity->getPosX() > m_desiredPlayerRightDistance || entity->getPosX() < m_desiredPlayerLeftDistance) {
		context->setState(unique_ptr < IFSMBoss > { new RangedAttackState });
	}
	else if (playerFeets > entity->getPosY() && distance < CLOSECOMBAT_RAM_DISTANCE) {
		context->setState(unique_ptr < IFSMBoss > { new CloseCombatState(entity) });
	}
	else if (!m_isActuallyFleeing) {
		int dice = rand() % 6;
		if (dice < 3) {
			entity->setSpeedX(150);
		}
		else {
			entity->setSpeedX(-150);
		}
		m_isActuallyFleeing = true;
		
	}


}