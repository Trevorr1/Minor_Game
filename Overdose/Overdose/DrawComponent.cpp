#include "DrawComponent.h"
#include "GameEntity.h"

using namespace overdose;


DrawComponent::DrawComponent(char* aFilePath, unsigned int numFrames)
{
	m_SpritSheet = new Sprite(new Surface(aFilePath), numFrames);
}


DrawComponent::~DrawComponent()
{
	delete m_SpritSheet;
}

void DrawComponent::receive(Component &component, int message)
{

}

void DrawComponent::tick(GameEntity &entity, Surface* a_Target)
{
	m_SpritSheet->Draw((int)entity.getPosX(), (int)entity.getPosY(), a_Target);
}