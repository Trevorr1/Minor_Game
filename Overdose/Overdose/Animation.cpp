#include "Animation.h"

using namespace overdose;



Animation::Animation(char* aFilePath, unsigned int numFrames){
	m_SpriteSheet = new Sprite(new Surface(aFilePath), numFrames, 0);
}
Animation::Animation(char* aFilePath, unsigned int numFrames, unsigned int FPS)
{
	m_SpriteSheet = new Sprite(new Surface(aFilePath), numFrames, FPS);
	m_FPS = FPS;
	m_timePerFrame = 1000.0f / (float)FPS;
}


Animation::~Animation()
{

}
