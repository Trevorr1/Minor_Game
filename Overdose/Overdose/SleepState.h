#pragma once
#include "IFSMBoss.h"
#include "LevelManager.h"
#include <ctime>

#define BOSS_SLEEPTIME_SECS 0.4


namespace overdose{
	class SleepState : public IFSMBoss {
	private:
		int m_OldXSpeed;
		time_t m_SleepStartTime;
	public:
		SleepState(GameEntity* entity);
		void handle(AIComponent *context, GameEntity *entity);

	};
}