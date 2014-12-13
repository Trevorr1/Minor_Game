#pragma once
#include "IFSMBoss.h"
#include "LevelManager.h"
namespace overdose{
	class FollowState : public IFSMBoss {
	public:
		FollowState::FollowState();
		void handle(AIComponent *context, GameEntity *entity);

	};
}