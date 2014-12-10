#include "CloseCombatState.h"
#include "AIComponent.h"
#include "FollowState.h"
using namespace overdose;

CloseCombatState::CloseCombatState(GameEntity *entity) {
	GameEntity *player = LevelManager::getInstance().getCurrentLevel()->getPlayerEntity();

	if (player->getPosX() < entity->getPosX()) {
		m_direction = CloseCombatStateDirection::Left;
	}
	else {
		m_direction = CloseCombatStateDirection::Right;
	}

	entity->setSpeedX(entity->getSpeedX() * 10);
}

void CloseCombatState::handle(AIComponent *context, GameEntity *entity) {
	GameEntity *player = LevelManager::getInstance().getCurrentLevel()->getPlayerEntity();


	
	if ((player->getPosX() > entity->getPosX() + CLOSECOMBAT_RAM_DISTANCE && m_direction == CloseCombatStateDirection::Left) ||
		(player->getPosX() < entity->getPosX() - CLOSECOMBAT_RAM_DISTANCE && m_direction == CloseCombatStateDirection::Right))
	{
		entity->setSpeedX(entity->getSpeedX() / 10);
		context->setState(std::unique_ptr < IFSMBoss > {new FollowState});
		
	}

}