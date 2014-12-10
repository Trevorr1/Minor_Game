#pragma once
#include <memory.h>
namespace overdose {
	class AIComponent;
	class GameEntity;
	class IFSMBoss {
	public:
		virtual void handle(AIComponent *context, GameEntity *entity) = 0;
	};
}