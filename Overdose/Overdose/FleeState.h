#pragma once
#include "IFSMBoss.h"
#include "LevelManager.h"
namespace overdose{
	class FleeState : public IFSMBoss {
	private:
		int m_desiredPlayerLeftDistance;
		int m_desiredPlayerRightDistance;
	public:
		FleeState::FleeState(GameEntity *entity);
		void handle(AIComponent *context, GameEntity *entity);

	};
}