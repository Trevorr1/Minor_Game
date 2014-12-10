#include "FlyAttackState.h"
#include "AIComponent.h"
#include "FollowState.h"
using namespace overdose;

FlyAttackState::FlyAttackState(GameEntity *entity) {
	GameEntity *player = LevelManager::getInstance().getCurrentLevel()->getPlayerEntity();

	if (player->getPosX() < entity->getPosX()) {
		m_direction = FlyAttackDirection::Left;
	}
	else {
		m_direction = FlyAttackDirection::Right;
	}

	entity->setSpeedX(entity->getSpeedX() * 10);
}

void FlyAttackState::handle(AIComponent *context, GameEntity *entity) {
	GameEntity *player = LevelManager::getInstance().getCurrentLevel()->getPlayerEntity();
	
	if ( (player->getPosX() > entity->getPosX() + 200 && m_direction == FlyAttackDirection::Left) ||
		 (player->getPosX() < entity->getPosX() - 200 && m_direction == FlyAttackDirection::Right) )
	{
		entity->setSpeedX(entity->getSpeedX() / 10);
		context->setState(std::unique_ptr < IFSMBoss > {new FollowState});
		
	}

}