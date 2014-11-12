#pragma once
#include "Component.h"
using std::string;
namespace overdose{
	class KillSwitchComponent :
		public Component
	{
	private:
		float m_maxDt;
		float m_totalDt = 0.0;
	public:

		KillSwitchComponent(float maxDt);
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(float dt, GameEntity *entity);
		string getComponentID();
	};

}