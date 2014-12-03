#include "EnemyMoveComponent.h"

using namespace overdose;

EnemyMoveComponent::EnemyMoveComponent(int minX, int maxX)
{
	m_minX = minX;
	m_maxX = maxX;
	m_minSpeedX = -110;
	m_maxSpeedX = 110;
	m_currentSpeedX = 0.0f;
}

EnemyMoveComponent::~EnemyMoveComponent()
{

}

void  EnemyMoveComponent::receive(Component *subject, ComponentMessage message, GameEntity *object)
{

}


void EnemyMoveComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages){}

void  EnemyMoveComponent::tick(float dt, GameEntity *entity)
{
	int posx = (int)entity->getPosX();
	m_currentSpeedX += (float)m_maxSpeedX*0.3f;
	if (m_currentSpeedX > m_maxSpeedX) m_currentSpeedX = m_maxSpeedX;
	if (m_currentSpeedX < m_minSpeedX) m_currentSpeedX = m_minSpeedX;
	entity->setSpeedX(m_currentSpeedX);

	if (posx < m_minX && entity->getSpeedX() < 0)
	{
		//entity->setSpeedX(entity->getSpeedX() * -1);
		m_maxSpeedX *= -1;
		int stop = 0;
	}
	if (posx > m_maxX && entity->getSpeedX() > 0)
	{
		//entity->setSpeedX(entity->getSpeedX() * -1);
		m_maxSpeedX *= -1;
		int stop = 0;
	}
	if (entity->getPosX() < m_minX) 
	{
		entity->setPosX(m_minX + 5);
	}
	if (entity->getPosX() > m_maxX)
	{
		entity->setPosX(m_maxX - 5);
	}
}

std::string EnemyMoveComponent::getComponentID(){
	return "EnemyMoveComponent";
}
