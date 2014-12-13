#pragma once
#include "IFSMBoss.h"
#include "LevelManager.h"
#include <ctime>

#define SECONDS_BETWEEN_SHOTS 1
#define RANGED_MAX_DISTANCE 500
#define RANGED_MIN_DISTANCE 350

namespace overdose{
	class RangedAttackState : public IFSMBoss {
	private:
		time_t m_lastFired = 0;
	public:
		RangedAttackState::RangedAttackState();
		void handle(AIComponent *context, GameEntity *entity);

	};
}