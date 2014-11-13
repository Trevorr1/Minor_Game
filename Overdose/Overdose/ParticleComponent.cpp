#include "ParticleComponent.h"

using namespace overdose;

ParticleComponent::ParticleComponent(float maxDt) {
	m_maxDt = maxDt;
}

void ParticleComponent::createParticleFor(GameEntity *entity) {
	/* misschien in factory stoppen? Idk D:*/
	GameEntity *particle = new GameEntity(Particle);
	particle->addComponent(new MoveComponent);
	particle->addComponent(new KillSwitchComponent(0.5));
	std::map<eAnimationState, Animation*>* animations = new std::map<eAnimationState, Animation*>();
	animations->insert({ Default, new Animation("assets/sprites/smileyface.png", 1) });
	DrawComponent *animation = new DrawComponent(animations);
	animation->setAnimation(Default);//set starting animation
	particle->addComponent(animation);

	particle->setPosY(entity->getPosY() + rand() % 10); // netter als we het niet op de game entity laten spawnen?
	particle->setPosX(entity->getPosX() + rand() % 10);

	particle->setSpeedX(-250 + rand() % 500); // uiteraard hier iets met angles doen
	particle->setSpeedY(-250 + rand() % 500);

	LevelManager::getInstance().getCurrentLevel()->scheduleEntityForInsertion(particle);
}

void ParticleComponent::tick(float dt, GameEntity *entity) {
	bool hasFiredParticle = false;
	m_totalDt += dt;

	// mensen met trage PC's (en dus hoge DT) moeten gecompenseerd worden met extra veel particles :D
	while (m_totalDt >= m_maxDt) {
		m_totalDt -= m_maxDt;
		hasFiredParticle = true;
		createParticleFor(entity); 
	}

	if (m_totalDt < m_maxDt && hasFiredParticle) {
		m_totalDt = 0;
	}

}

void ParticleComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

}

string ParticleComponent::getComponentID() {
	return "ParticleComponent";
}