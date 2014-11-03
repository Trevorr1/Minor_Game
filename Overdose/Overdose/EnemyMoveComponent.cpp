#include "EnemyMoveComponent.h"

using namespace overdose;

EnemyMoveComponent::EnemyMoveComponent(int minX, int maxX)
{
	m_minX = minX;
	m_maxX = maxX;
}

EnemyMoveComponent::~EnemyMoveComponent()
{

}

void  EnemyMoveComponent::receive(Component *subject, ComponentMessage message, GameEntity *object)
{

}

void  EnemyMoveComponent::tick(float dt, GameEntity *entity)
{

	if (entity->getPosX() < m_minX || entity->getPosX() > m_maxX)
	{
		entity->setSpeedX(entity->getSpeedX() * -1);
	}
	if (entity->getPosX() < m_minX) {
		entity->setPosX(m_minX + 5);
	}
	if (entity->getPosX() > m_maxX) {
		entity->setPosX(m_maxX - 5);
	}
}

std::string EnemyMoveComponent::getComponentID(){
	return "EnemyMoveComponent";
}
