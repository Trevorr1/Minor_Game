#include "DrawComponent.h"
#include "GameEntity.h"
#include "DrawManager.h"

using namespace overdose;


DrawComponent::DrawComponent(char* aFilePath, unsigned int numFrames)
{
	m_SpritSheet = new Sprite(new Surface(aFilePath), numFrames);
}
DrawComponent::DrawComponent(char* aFilePath, unsigned int numFrames, unsigned int FPS)
{
	m_SpritSheet = new Sprite(new Surface(aFilePath), numFrames);
	m_FPS = FPS;
	m_timePerFrame = 1000.0f / (float)FPS;
}


DrawComponent::~DrawComponent()
{
	delete m_SpritSheet;
}

void DrawComponent::init(GameEntity *entity) {
	entity->setHeight((float)m_SpritSheet->GetHeight());
	entity->setWidth((float)m_SpritSheet->GetWidth());
}

void DrawComponent::receive(Component *subject, ComponentMessage message, GameEntity *objects)
{

}

void DrawComponent::tick(float dt, GameEntity *entity)
{
	m_SpritSheet->Draw((int)entity->getPosX(), (int)entity->getPosY(), DrawManager::getInstance()->getSurface());

	if (m_FPS > 0){
		m_currentDTcount += dt;
		while (m_currentDTcount > m_timePerFrame){
			NextSprite();
			m_currentDTcount -= m_timePerFrame;
		}
	}


}

void DrawComponent::NextSprite()
{
	if ((m_SpritSheet->Frames() - 1) == m_SpritSheet->GetCurrentFrame())
	{
		m_SpritSheet->SetFrame(0);
	}
	else
	{
		m_SpritSheet->SetFrame(m_SpritSheet->GetCurrentFrame() + 1);
	}
}

std::string DrawComponent::getComponentID(){
	return "DrawComponent";
}
