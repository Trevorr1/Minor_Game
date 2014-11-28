#include "MouseBaseComponent.h"
#include "DrawManager.h"
namespace overdose {
	class GameEntity;

	class MouseOverEffectComponent : public MouseBaseComponent
	{
	public:
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();
	};
}