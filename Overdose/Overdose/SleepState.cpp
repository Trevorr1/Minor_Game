#include "SleepState.h"
#include "AIComponent.h"
using namespace overdose;
SleepState::SleepState(GameEntity* entity) {
	printf("Boss - SleepState\n");

	m_OldXSpeed = entity->getSpeedX();

	entity->setSpeedX(0);
	m_SleepStartTime = time(nullptr);
}
void SleepState::handle(AIComponent *context, GameEntity *entity) {

	time_t currentTime = std::time(nullptr);

	if (std::difftime(currentTime, m_SleepStartTime) > BOSS_SLEEPTIME_SECS)  {
		entity->setSpeedX(m_OldXSpeed);
		context->setState(unique_ptr < IFSMBoss > {new FollowState});
	}
	
}