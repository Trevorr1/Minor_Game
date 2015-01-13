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

	float SECONDS_BETWEEN_SHOTS = 1;

	if (entity->getHealth() == 2) {
		SECONDS_BETWEEN_SHOTS = SECONDS_BETWEEN_SHOTS / 2;
	}
	else if (entity->getHealth() == 1) {	
		SECONDS_BETWEEN_SHOTS = SECONDS_BETWEEN_SHOTS / 4;
	}
		

	if (distance < RANGED_MIN_DISTANCE) {
		printf("Boss - FU tried to shoot but changed his mind after seeing your butt.\n");
	}
	else if (std::difftime(currentTime, m_lastFired) > SECONDS_BETWEEN_SHOTS) {
		m_lastFired = currentTime;

		


		GameEntity *bullet = GameEntityFactory::getInstance().getGameEntity(Bullet);
		bullet->setSpeedX(500);
		bullet->setPosX(entity->getPosX() -10);
		bullet->setPosY(entity->getPosY());

		


		if (player->getPosX() < entity->getPosX()) {
			bullet->setSpeedX(bullet->getSpeedX() * -1);
			bullet->setSpeedY(-1* rc * 500);
		}
		else {
			bullet->setSpeedY(rc * 500);
		}
		LevelManager::getInstance().getCurrentLevel()->scheduleEntityForInsertion(bullet);
		SoundManager::getInstance().PlaySound(Gunshot);

	}


	if (distance > RANGED_MAX_DISTANCE) {
		context->setState(std::unique_ptr < IFSMBoss > {new FollowState });
	}
	else if (distance < RANGED_MIN_DISTANCE) {
		context->setState(std::unique_ptr < IFSMBoss > { new CloseCombatState(entity)});
	}
	

}