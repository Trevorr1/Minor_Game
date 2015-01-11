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
	m_canHurt->push_back(Urquhart);
	m_canHurt->push_back(Bullet);
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
	m_Subject = entity;
}

void HealthComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) 
{

	// environment / drugs shouldn't never hurt the entity
	if (object->getEnum() == Grass || object->getEnum() == Drug_Speed || object->getEnum() == Flag) 
	{
		return;
	}


	auto it_hurtable = std::find(m_canHurt->begin(), m_canHurt->end(), object->getEnum());

	if (it_hurtable == m_canHurt->end())
	{
		// If not in the list, the entity is not hurtable.
		return;
	}


	// HACK!
	if (object->getEnum() == Bullet) {
		object->scheduleForRemoval();
	}
	else if (message != MoveComponent_OUTOFAREA && m_Subject->isJumping()) {
		return;
	}

	// Hacky as well :D
	//if (object->getEnum() == Player && m_Subject->isJumping()) {
	//	return;
	//}

	if (m_invincibleTime > 0)
	{
		//std::cout << "Entity " << object->getEnum() << " is invincible for now." << std::endl;
		return;
	}

	auto it = std::find(m_healthDecreaseReactionList->begin(), m_healthDecreaseReactionList->end(), message);

	// Vector list contains message?
	if (it != m_healthDecreaseReactionList->end())
	{
		m_invincibleTime = 1;
		m_scheduleHealthDecrease = true;
	}
}


void HealthComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages)
{
	for (std::map<ComponentMessage, GameEntity*>::iterator it = messages.begin(); it != messages.end(); ++it)
	{
		// environment / drugs shouldn't never hurt the entity
		if (it->second->getEnum() == Grass || it->second->getEnum() == Drug_Speed || it->second->getEnum() == Flag) {
			return;
		}

		auto it_hurtable = std::find(m_canHurt->begin(), m_canHurt->end(), it->second->getEnum());

		if (it_hurtable == m_canHurt->end()) {
			// If not in the list, the entity is not hurtable.
			return;
		}
		// HACK!
		if (it->second->getEnum() == Bullet) {
			it->second->scheduleForRemoval();
		}
		else if (it->first != MoveComponent_OUTOFAREA && m_Subject->isJumping()) {
			return;
		}

		// Hacky as well :D
	/*	if (it->second->getEnum() == Player && it->second->isJumping()) {
			return;
		}*/



		if (m_invincibleTime > 0) {
			//std::cout << "Entity " << it->second->getEnum() << " is invincible for now." << std::endl;
			return;
		}

		auto hit = std::find(m_healthDecreaseReactionList->begin(), m_healthDecreaseReactionList->end(), it->first);

		// Vector list contains message?
		if (hit != m_healthDecreaseReactionList->end()) {
			m_invincibleTime = 0.5;
			m_scheduleHealthDecrease = true;
		}
	}
}

void HealthComponent::tick(float dt, GameEntity *entity) {
	if (m_scheduleHealthDecrease) {
		if (entity->getEnum() == Player) {
			SoundManager::getInstance().PlaySound(Ouch);
		}
		m_health--;
		//std::cout << "Entity " << entity->getEnum() << " health has been decreased" << std::endl;
		m_scheduleHealthDecrease = false;
		entity->broadcast(this, HealthComponent_HEALTH_DECREASED, entity);
		if (entity->getEnum() != Player) {

			//if (!firstBlood) {
				/* TODO: Deze wordt wel 10x aangeroepen per keer dat je een enemy dood.. wtf man... */
				entity->delayedAddComponent(new ParticleComponent(Blood, 0.01, 0.5, 0.5));
				//entity->delayedAddComponent(new KillSwitchComponent(0.3));
			//	firstBlood = true; // there you go @ wtf man.
		//	}

		}
	}
	if (m_health <= 0) {
	//	entity->scheduleForRemoval();
		if (entity->getEnum() != Player) {

			if (!firstBlood) {
				/* TODO: Deze wordt wel 10x aangeroepen per keer dat je een enemy dood.. wtf man... */
				entity->delayedAddComponent(new ParticleComponent(Blood, 0.01, 0.5, 0.5));
				entity->delayedAddComponent(new KillSwitchComponent(0.3));
				firstBlood = true; // there you go @ wtf man.
			}

		}
		else{
			entity->scheduleForRemoval();
		}
	}

	if (m_invincibleTime > 0) {
		m_invincibleTime -= dt;
	}


}

std::string HealthComponent::getComponentID() {
	return "HealthComponent";
}