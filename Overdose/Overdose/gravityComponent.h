#pragma once
#include "Component.h"

namespace overdose {

	class gravityComponent :
		public Component
	{
	public:
		gravityComponent();
		gravityComponent(float aGravity);
		virtual ~gravityComponent();

		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();

	private:
		float gravity;
	};

} // namespace overdose