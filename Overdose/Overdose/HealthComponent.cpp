#include "HealthComponent.h"
using namespace overdose;

HealthComponent::HealthComponent(int health) {
	m_healthDecreaseReactionList = new std::vector < ComponentMessage > ;

	m_healthDecreaseReactionList->push_back(ComponentMessage::CollissionComponent_REACTION_TOP);
	m_healthDecreaseReactionList->push_back(ComponentMessage::CollissionComponent_REACTION_LEFT);
	m_healthDecreaseReactionList->push_back(ComponentMessage::CollissionComponent_REACTION_RIGHT);
	m_healthDecreaseReactionList->push_back(ComponentMessage::MoveComponent_OUTOFAREA);
	m_health = health;
}



HealthComponent::HealthComponent(int health, std::vector<ComponentMessage> *healthDecreaseReactionList) {
	m_health = health;
	m_healthDecreaseReactionList = healthDecreaseReactionList;
}

HealthComponent::~HealthComponent() {
	delete m_healthDecreaseReactionList;
}

void HealthComponent::init(GameEntity* entity) {
	entity->setHealthPointer(&m_health);
}

void HealthComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

	if (m_invincibleTime > 0) {
		return;
	}


	// environment / drugs shouldn't hurt the entity
	if (object->getEnum() == Grass || object->getEnum() == Drug_Speed) {
		return;
	}

	auto it = std::find(m_healthDecreaseReactionList->begin(), m_healthDecreaseReactionList->end(), message);

	// Vector list contains message?
	if (it != m_healthDecreaseReactionList->end()) {
		m_invincibleTime = 1000;
		m_scheduleHealthDecrease = true;
	}
}

void HealthComponent::tick(float dt, GameEntity *entity) {
	if (m_scheduleHealthDecrease) {
		
		m_health--;
		std::cout << "Entity " << entity->getEnum() << " health has been decreased" << std::endl;
		m_scheduleHealthDecrease = false;
		entity->broadcast(this, HealthComponent_HEALTH_DECREASED, entity);
	}
	if (m_health <= 0) {
		entity->scheduleForRemoval();
	}

	if (m_invincibleTime >= 0) {
		m_invincibleTime -= dt;

	}


}

std::string HealthComponent::getComponentID() {
	return "HealthComponent";
}