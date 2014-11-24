#pragma once
#include "surface.h"

namespace overdose {

	class Animation
	{
	private:
		Sprite* m_SpriteSheet;
		unsigned int m_FPS = 0;
		float m_timePerFrame = 0.0f;

	public:
		Animation(char* aFilePath, unsigned int numFrames);
		Animation(char* aFilePath, unsigned int numFrames, unsigned int FPS);
		~Animation();

		Sprite* getSpriteSheet(){ return m_SpriteSheet; }
		unsigned int getTimePerFrame(){ return (int)m_timePerFrame; }
		unsigned int getFPS(){ return m_FPS; }
	};

}