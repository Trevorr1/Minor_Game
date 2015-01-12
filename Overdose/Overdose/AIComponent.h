#pragma once
#include "Component.h"
#include <memory>
#include "IFSMBoss.h"
#include "FollowState.h"
#include "SoundManager.h"
using std::string;
using std::unique_ptr;
namespace overdose{
	class AIComponent :
		public Component
	{
	private:
		unique_ptr<IFSMBoss> m_state{ new FollowState  };
	public:

		AIComponent();
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		string getComponentID();

		void setState(unique_ptr<IFSMBoss> state);
	};

}