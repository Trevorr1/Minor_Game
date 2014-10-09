#pragma once
#include "Component.h"
#include "surface.h"

namespace overdose {
	class DrawComponent : public Component
	{
	public:
		DrawComponent(char* aFilePath, unsigned int numFrames);
		virtual ~DrawComponent();

		void receive(Component *subject, int message, GameEntity *object);
		void tick(GameEntity *entity);

	private:
		Sprite* m_SpritSheet;
	};
}
