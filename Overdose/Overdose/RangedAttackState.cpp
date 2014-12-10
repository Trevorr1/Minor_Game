#include "RangedAttackState.h"
#include "AIComponent.h"
#include "FlyAttackState.h"
#include "GameEntityFactory.h"
using namespace overdose;

void RangedAttackState::handle(AIComponent *context, GameEntity *entity) {
	GameEntity *player = LevelManager::getInstance().getCurrentLevel()->getPlayerEntity();

	time_t currentTime = std::time(nullptr);

	if (std::difftime(currentTime, m_lastFired) > SECONDS_BETWEEN_SHOTS) {
		m_lastFired = currentTime;

		GameEntity *bullet = GameEntityFactory::getInstance().getGameEntity(Bullet);
		bullet->setSpeedX(750);
		bullet->setPosX(entity->getPosX() -10);
		bullet->setPosY(entity->getPosY());

		if (player->getPosX() < entity->getPosX()) {
			bullet->setSpeedX(bullet->getSpeedX() * -1);
		}
		LevelManager::getInstance().getCurrentLevel()->scheduleEntityForInsertion(bullet);

	}
	int distance = abs(player->getPosX() - entity->getPosX());
	if (distance > RANGED_MAX_DISTANCE) {
		context->setState(std::unique_ptr < IFSMBoss > {new FollowState });
	}
	else if (distance < RANGED_MIN_DISTANCE) {
		context->setState(std::unique_ptr < IFSMBoss > { new FlyAttackState(entity)});
	}
	

}