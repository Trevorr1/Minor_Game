#include "DrawComponent.h"
#include "GameEntity.h"
#include "DrawManager.h"

using namespace overdose;

DrawComponent::DrawComponent(std::map<eAnimationState, Animation*>* animations){
	m_Animations = animations;
}


DrawComponent::~DrawComponent()
{
	delete m_SpriteSheet;
}

void DrawComponent::init(GameEntity *entity) {
	entity->setHeight((float)m_SpriteSheet->GetHeight());
	entity->setWidth((float)m_SpriteSheet->GetWidth());
}

void DrawComponent::receive(Component *subject, ComponentMessage message, GameEntity *objects)
{

}

void DrawComponent::tick(float dt, GameEntity *entity)
{
	m_SpriteSheet->Draw((int)entity->getPosX(), (int)entity->getPosY(), DrawManager::getInstance()->getSurface());

	if (m_FPS > 0){
		m_currentDTcount += dt;
		while (m_currentDTcount > m_timePerFrame){
			NextSprite();
			m_currentDTcount -= m_timePerFrame;
		}
	}

	if (entity->getSpeedX() == 0){
		setAnimation(Idle);
	}
	else if (entity->getSpeedX() > 0){
		setAnimation(Walk);
	}
	else{
		setAnimation(Walk);
	}

}

void DrawComponent::NextSprite()
{
	if ((m_SpriteSheet->Frames() - 1) == m_SpriteSheet->GetCurrentFrame())
	{
		m_SpriteSheet->SetFrame(0);
	}
	else
	{
		m_SpriteSheet->SetFrame(m_SpriteSheet->GetCurrentFrame() + 1);
	}
}

std::string DrawComponent::getComponentID(){
	return "DrawComponent";
}


void DrawComponent::setAnimation(eAnimationState state){
	if (m_Animations->count(state)){
		switch (state){
			case Walk:
				setCurrentAnimation(m_Animations->find(Walk)->second);
				break;
			case Idle:
				setCurrentAnimation(m_Animations->find(Idle)->second);
				break;
			case Attack:
				setCurrentAnimation(m_Animations->find(Attack)->second);
				break;
			case Jump:
				setCurrentAnimation(m_Animations->find(Jump)->second);
				break;
			case Fall:
				setCurrentAnimation(m_Animations->find(Fall)->second);
				break;
			default:
				break;
		}
	}
}

void DrawComponent::setCurrentAnimation(Animation* animation){
	if (animation == nullptr){
		return;
	}
	m_SpriteSheet = animation->getSpriteSheet();
	m_FPS = animation->getFPS();
	m_timePerFrame = animation->getTimePerFrame();
}