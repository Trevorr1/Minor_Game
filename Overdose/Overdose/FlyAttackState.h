#pragma once
#include "IFSMBoss.h"
#include "LevelManager.h"
namespace overdose{
	enum class FlyAttackDirection { Left, Right };
	class FlyAttackState : public IFSMBoss {
	private:
		FlyAttackDirection m_direction;
	public:
		FlyAttackState(GameEntity* entity);
		void handle(AIComponent *context, GameEntity *entity);

	};
}