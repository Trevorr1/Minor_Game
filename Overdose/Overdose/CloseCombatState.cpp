#include "CloseCombatState.h"
#include "AIComponent.h"
#include "SleepState.h"
using namespace overdose;


CloseCombatState::CloseCombatState(GameEntity *entity) {
	printf("Boss - CloseCombatState\n");
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


	int distance = abs(player->getPosX() - entity->getPosX());
	if ((player->getPosX() > entity->getPosX() + CLOSECOMBAT_RAM_DISTANCE && m_direction == CloseCombatStateDirection::Left) ||
		(player->getPosX() < entity->getPosX() - CLOSECOMBAT_RAM_DISTANCE && m_direction == CloseCombatStateDirection::Right) || distance > 500)
	{
		entity->setSpeedX(entity->getSpeedX() / 10);
		context->setState(std::unique_ptr < IFSMBoss > {new SleepState(entity)});
		
	}

	if (entity->getSpeedX() == 0) {
		context->setState(std::unique_ptr < IFSMBoss > {new SleepState(entity)});
	}

}