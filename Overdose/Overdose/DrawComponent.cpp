#include "DrawComponent.h"
#include "GameEntity.h"
#include "DrawManager.h"

using namespace overdose;


DrawComponent::DrawComponent(char* aFilePath, unsigned int numFrames)
{
	m_SpritSheet = new Sprite(new Surface(aFilePath), numFrames);
}


DrawComponent::~DrawComponent()
{
	delete m_SpritSheet;
}

void DrawComponent::init(GameEntity *entity) {
	entity->setHeight(m_SpritSheet->GetHeight());
	entity->setWidth(m_SpritSheet->GetWidth());
}

void DrawComponent::receive(Component *subject, ComponentMessage message, GameEntity *objects)
{

}

void DrawComponent::tick(float dt, GameEntity *entity)
{
	m_SpritSheet->Draw((int)entity->getPosX(), (int)entity->getPosY(), DrawManager::getInstance()->getSurface());
}

std::string DrawComponent::getComponentID(){
	return "DrawComponent";
}