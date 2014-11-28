#pragma once
#include "Component.h"
#include "InputManager.h"
namespace overdose {
	class MouseBaseComponent : public Component {
	protected:
		bool isMouseHover(GameEntity* entity, int x, int y);
	public:
		//std::string getComponentID();
	//	void receive(Component *subject, ComponentMessage message, GameEntity *object);
	//	virtual void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);

	//	virtual void tick(float dt, GameEntity *entity) = 0;
	};
}