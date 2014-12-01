#include "HealthComponent.h"
using namespace overdose;

HealthComponent::HealthComponent(int health) {
	m_healthDecreaseReactionList = new vector < ComponentMessage >;

	m_healthDecreaseReactionList->push_back(ComponentMessage::CollissionComponent_REACTION_TOP);
	m_healthDecreaseReactionList->push_back(ComponentMessage::CollissionComponent_REACTION_LEFT);
	m_healthDecreaseReactionList->push_back(ComponentMessage::CollissionComponent_REACTION_RIGHT);
	m_healthDecreaseReactionList->push_back(ComponentMessage::MoveComponent_OUTOFAREA);
	m_health = health;

	m_canHurt = new vector < eGameEntity >;
	m_canHurt->push_back(Policeman);
	m_canHurt->push_back(Player);
}



HealthComponent::HealthComponent(int health, vector<ComponentMessage> *healthDecreaseReactionList, vector<eGameEntity>* canHurt) {
	m_health = health;
	m_healthDecreaseReactionList = healthDecreaseReactionList;
	m_canHurt = canHurt;
}

HealthComponent::~HealthComponent() {
	delete m_healthDecreaseReactionList;
	delete m_canHurt;
}

void HealthComponent::init(GameEntity* entity) {
	entity->setHealthPointer(&m_health);
}

void HealthComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {



	// environment / drugs shouldn't never hurt the entity
	if (object->getEnum() == Grass || object->getEnum() == Drug_Speed || object->getEnum() == Flag) {
		return;
	}

	auto it_hurtable = std::find(m_canHurt->begin(), m_canHurt->end(), object->getEnum());

	if (it_hurtable == m_canHurt->end()) {
		// If not in the list, the entity is not hurtable.
		return;
	}



	if (m_invincibleTime > 0) {
		std::cout << "Entity " << object->getEnum() << " is invincible for now." << std::endl;
		return;
	}

	auto it = std::find(m_healthDecreaseReactionList->begin(), m_healthDecreaseReactionList->end(), message);

	// Vector list contains message?
	if (it != m_healthDecreaseReactionList->end()) {
		m_invincibleTime = 1;
		m_scheduleHealthDecrease = true;
	}
}


void HealthComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {

}

void HealthComponent::tick(float dt, GameEntity *entity) {
	if (m_scheduleHealthDecrease) {
		if (entity->getEnum() == Player) {
			SoundManager::getInstance().PlaySound(Ouch);
		}
		m_health--;
		std::cout << "Entity " << entity->getEnum() << " health has been decreased" << std::endl;
		m_scheduleHealthDecrease = false;
		entity->broadcast(this, HealthComponent_HEALTH_DECREASED, entity);
	}
	if (m_health <= 0) {
	//	entity->scheduleForRemoval();
		if (entity->getEnum() != Player) {
			entity->delayedAddComponent(new ParticleComponent(Blood, 0.01, 0.5, 0.5));
			entity->delayedAddComponent(new KillSwitchComponent(0.3));
		}
	}

	if (m_invincibleTime > 0) {
		m_invincibleTime -= dt;
	}


}

std::string HealthComponent::getComponentID() {
	return "HealthComponent";
}