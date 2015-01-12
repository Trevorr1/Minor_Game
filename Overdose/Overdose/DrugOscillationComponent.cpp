#include "DrugOscillationComponent.h"
#include "LevelManager.h"
#include <ctime>
#include <math.h>

using namespace overdose;

DrugOscillationComponent::DrugOscillationComponent()
{
	m_Begin = clock();
}


DrugOscillationComponent::~DrugOscillationComponent()
{
}

void DrugOscillationComponent::receive(Component *subject, ComponentMessage message, GameEntity *object)
{

}

void DrugOscillationComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages)
{

}

void DrugOscillationComponent::tick(float dt, GameEntity *entity)
{
	float center = entity->getPosY();
	float offset = 0; //The offset to add to your Y
	float radius = 100; //Whatever you want your radius to be

	dt = (dt / LevelManager::getInstance().getSpeedModifier());
	
	
	// this code has some hard-coded values works for now but should be changed
	clock_t end = clock();
	double elapsed_ms = double(end - m_Begin) / (CLOCKS_PER_SEC);
	elapsed_ms *= 5;
	offset = (float)sin(elapsed_ms) * radius;
	offset *= dt;
	entity->setPosY(center - offset);
}

std::string DrugOscillationComponent::getComponentID()
{
	return "DrugOscillationComponent";
}