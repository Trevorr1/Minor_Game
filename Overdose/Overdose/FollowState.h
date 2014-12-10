#pragma once
#include "IFSMBoss.h"
#include "LevelManager.h"
namespace overdose{
	class FollowState : public IFSMBoss {
	public:
		void handle(AIComponent *context, GameEntity *entity);

	};
}