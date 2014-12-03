#include "ParticleComponent.h"

using namespace overdose;

ParticleComponent::ParticleComponent(ParticleType type, float maxDt, float lifetime, float selfDestructIn) {
	m_maxDt = maxDt;
	m_type = type;
	m_lifetime = lifetime;
	m_selfDestruct = selfDestructIn;
}

void ParticleComponent::createParticleFor(GameEntity *entity) {
	/* misschien in factory stoppen? Idk D:*/
	std::map<eAnimationState, Animation*>* animations = new std::map<eAnimationState, Animation*>();

	if (m_type == SmileyFace || m_type == Blood) {
		animations->insert({ Default, new Animation(getSpritePath(), 1) });
	}
	else {
		animations->insert({ Default, new Animation(getSpritePath(), 4, 20) });
	}
	DrawComponent *animation = new DrawComponent(animations);
	animation->setAnimation(Default);//set starting animation

	GameEntity *particle = new GameEntity(Particle, new MoveComponent, new KillSwitchComponent(m_lifetime), new gravityComponent(), animation, FinalComponent);
	particle->setPosY(entity->getPosY() + rand() % 10); // netter als we het niet op de game entity laten spawnen?
	particle->setPosX(entity->getPosX() + rand() % 10);

	particle->setSpeedX(float(-250 + rand() % 500)); // uiteraard hier iets met angles doen
	particle->setSpeedY(float(-250 + rand() % 500));

	LevelManager::getInstance().getCurrentLevel()->scheduleEntityForInsertion(particle);
}

char* ParticleComponent::getSpritePath() {
	switch (m_type) {
	case RedLum:
		return "assets/sprites/lum.png";
	case Blood:
		return "assets/sprites/blood.png";
	case SmileyFace:
	default:
		return "assets/sprites/smileyface.png";
	}
}

void ParticleComponent::tick(float dt, GameEntity *entity) {
	bool hasFiredParticle = false;
	m_totalDt += dt;
	m_selfLifetime += dt;

	// mensen met trage PC's (en dus hoge DT) moeten gecompenseerd worden met extra veel particles :D
	while (m_totalDt >= m_maxDt) {
		m_totalDt -= m_maxDt;
		hasFiredParticle = true;
		createParticleFor(entity); 
	}

	if (m_totalDt < m_maxDt && hasFiredParticle) {
		m_totalDt = 0;
	}

	if (m_selfDestruct != PARTICLES_FOREVER && m_selfLifetime  > m_selfDestruct) {
		entity->removeComponent(getComponentID());
	}

}

void ParticleComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

}


void ParticleComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {

}

string ParticleComponent::getComponentID() {
	return "ParticleComponent";
}