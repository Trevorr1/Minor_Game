#include "EnemyMoveComponent.h"
#include "LevelManager.h"

using namespace overdose;

bool sortByPosX(GameEntity* x, GameEntity* x2) { //todo: give this method a proper position in the code
	return x->getPosX() < x2->getPosX();
}

EnemyMoveComponent::EnemyMoveComponent()
{
	m_minX = 0;
	m_maxX = 0;
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
	if (m_maxX == 0 && m_minX == 0)
		calculateMinMax(entity);
	else
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
}

std::string EnemyMoveComponent::getComponentID(){
	return "EnemyMoveComponent";
}

void EnemyMoveComponent::calculateMinMax(GameEntity *entity)
{
	int entHeight = entity->getHeight();
	ILevel* level = LevelManager::getInstance().getCurrentLevel();
	vector<GameEntity*>* entities =  level->getEntities();
	vector<GameEntity*> entitiesOnSameHeight;
	for (int i = 0; i < entities->size(); i++)
	{
		GameEntity* ent = entities->at(i);
		int entPosY = entity->getPosY() + entHeight;
		if (ent->getEnum() == eGameEntity::Grass && ent->getPosY() == entPosY)
		{
			entitiesOnSameHeight.push_back(ent);
		}
	}
	std::sort(entitiesOnSameHeight.begin(), entitiesOnSameHeight.end(), sortByPosX);
	bool connected = true;
	bool enemyspawned = false;
	m_minX = entitiesOnSameHeight.at(0)->getPosX();
	for (int i = 0; i < entitiesOnSameHeight.size(); i++)
	{
		GameEntity* ent = entities->at(i);
		int currentXMin = ent->getPosX();
		int currentXMax = ent->getPosX() + ent->getWidth();

		if (!connected && !enemyspawned)
		{
			m_minX = entitiesOnSameHeight.at(i)->getPosX();
			connected = true;
		}

		if (entity->getPosX() < currentXMax && entity->getPosX() > currentXMin)
		{
			enemyspawned = true;
		}

		if (i != entitiesOnSameHeight.size() - 1)
		{
			if (connected &&  (currentXMax + ent->getWidth() == entitiesOnSameHeight.at(i)->getPosX()))
			{
				m_maxX = currentXMax;
			}
			else
			{
				connected = false;
			}
		}
		else
		{

		}
	}
	//m_minX = 300;
	int x = 0;
	//m_maxX = 600;

}