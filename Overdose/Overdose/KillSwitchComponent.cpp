#include "KillSwitchComponent.h"

using namespace overdose;

KillSwitchComponent::KillSwitchComponent(float maxDt) {
	m_maxDt = maxDt;
}

void KillSwitchComponent::tick(float dt, GameEntity *entity) {
	m_totalDt += dt;

	if (m_totalDt >= m_maxDt) {
		entity->scheduleForRemoval();
	}

}

void KillSwitchComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

}

string KillSwitchComponent::getComponentID() {
	return "KillSwitchComponent";
}