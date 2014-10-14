#pragma once
#include "Component.h"
#include "surface.h"

namespace overdose {
	class DrawComponent : public Component
	{
	public:
		DrawComponent(char* aFilePath, unsigned int numFrames);
		virtual ~DrawComponent();

		void init(GameEntity *entity);
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();
		

	private:
		Sprite* m_SpritSheet;
	};
}
