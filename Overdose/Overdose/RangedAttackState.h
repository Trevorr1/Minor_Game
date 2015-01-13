#pragma once
#include "IFSMBoss.h"
#include "LevelManager.h"
#include <ctime>

#define RANGED_MAX_DISTANCE 500
#define RANGED_MIN_DISTANCE 300

namespace overdose{
	class RangedAttackState : public IFSMBoss {
	private:
		time_t m_lastFired = 0;
	public:
		RangedAttackState::RangedAttackState();
		void handle(AIComponent *context, GameEntity *entity);

	};
}