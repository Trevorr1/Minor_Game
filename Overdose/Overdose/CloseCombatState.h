#pragma once
#include "IFSMBoss.h"
#include "LevelManager.h"

#define CLOSECOMBAT_RAM_DISTANCE 150

namespace overdose{
	enum class CloseCombatStateDirection { Left, Right };
	class CloseCombatState : public IFSMBoss {
	private:
		CloseCombatStateDirection m_direction;
	public:
		CloseCombatState(GameEntity* entity);
		void handle(AIComponent *context, GameEntity *entity);

	};
}