#include "RangedAttackState.h"
#include "AIComponent.h"
#include "CloseCombatState.h"
#include "GameEntityFactory.h"
using namespace overdose;

RangedAttackState::RangedAttackState() {
	printf("Boss - RangedAttackState\n");
}

void RangedAttackState::handle(AIComponent *context, GameEntity *entity) {
	GameEntity *player = LevelManager::getInstance().getCurrentLevel()->getPlayerEntity();
	int distance = abs(player->getPosX() - entity->getPosX());
	float rc = (entity->getPosY() - player->getPosY()) / (entity->getPosX() - player->getPosX());
	time_t currentTime = std::time(nullptr);

	if (std::difftime(currentTime, m_lastFired) > SECONDS_BETWEEN_SHOTS) {
		m_lastFired = currentTime;

		GameEntity *bullet = GameEntityFactory::getInstance().getGameEntity(Bullet);
		bullet->setSpeedX(500);
		bullet->setPosX(entity->getPosX() -10);
		bullet->setPosY(entity->getPosY());

		


		if (player->getPosX() < entity->getPosX()) {
			bullet->setSpeedX(bullet->getSpeedX() * -1);
			bullet->setSpeedY(-1* rc * 750);
		}
		LevelManager::getInstance().getCurrentLevel()->scheduleEntityForInsertion(bullet);

	}


	if (distance > RANGED_MAX_DISTANCE) {
		context->setState(std::unique_ptr < IFSMBoss > {new FollowState });
	}
	else if (distance < RANGED_MIN_DISTANCE) {
		context->setState(std::unique_ptr < IFSMBoss > { new CloseCombatState(entity)});
	}
	

}