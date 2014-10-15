#pragma once
#include "Component.h"
#include "surface.h"

namespace overdose {
	class DrawComponent : public Component
	{
	public:
		DrawComponent(char* aFilePath, unsigned int numFrames);
		DrawComponent(char* aFilePath, unsigned int numFrames, unsigned int FPS);
		virtual ~DrawComponent();

		void init(GameEntity *entity);
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();
	private:
		Sprite* m_SpritSheet;
		void NextSprite();
		unsigned int m_FPS = 0;
		float m_timePerFrame = 0.0f;
		float m_currentDTcount = 0.0f;
	};
}
