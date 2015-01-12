#include "DrugComponent.h"
#include "GameEntity.h"



using namespace overdose;

DrugComponent::DrugComponent()
{
	previous_speedX = -999;
	timer_start = NULL;
	level = LevelManager::getInstance().getCurrentLevel();
	surface = LevelManager::getInstance().getCurrentLevel()->getSurface();

	timer_particle = 500;
}


DrugComponent::~DrugComponent()
{
	//std::cout << "deleted DrugComponent" << std::endl;
	surface = NULL;
	level = NULL;
}

void DrugComponent::init(GameEntity* entity)
{
	this->entity = entity;
}

void DrugComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}

void DrugComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {
}

void DrugComponent::tick(float dt, GameEntity *entity) {
	if (timer_start == NULL){
		timer_start = getTimer_Start();
	}

	if (previous_speedX == -999){
		previous_speedX = entity->getMovementSpeed();
	}

	int timer_end = (int)((std::clock() - timer_start) / (double)(CLOCKS_PER_SEC / 1000));
	int drug_effect_ms = getDrugEffectMs();

	//particle checker
	if (timer_end > timer_particle){
		double incr_particle_timer = 1000;
		timer_particle += incr_particle_timer;
		//entity->delayedAddComponent(new ParticleComponent(SmileyFace, 0.1, incr_particle_timer / 1000, 0.1));
		insertParticleEffect(entity, incr_particle_timer);
	}

	// drug timer checker
	if (timer_end < drug_effect_ms)
	{
		float speed_drug = getDrugSpeed_X();
		entity->setMovementSpeed(previous_speedX * speed_drug);
		//entity->setSpeedX(previous_speedX * speed_drug);
		//std::cout << "Time: " << timer_end << " ms" << std::endl;
	}
	else{
		//entity->setSpeedX(previous_speedX);
		// Delete this drug component of gameEntity
		entity->setMovementSpeed(previous_speedX);
		entity->removeComponent(getComponentID());
		insertNegativeEffect(entity);
		//delete this drugcomponent
		// entity->insertNegativeEffect
		//delete this;
	}
}



float DrugComponent::getPrevious_SpeedX(){
	return previous_speedX;
}

int DrugComponent::getTimer_Start(){
	return std::clock();
}

float DrugComponent::getDrugSpeed_X(){
	return NULL;
}

int DrugComponent::getDrugEffectMs(){
	return NULL;
}

std::string DrugComponent::getComponentID(){
	return "DrugComponent";
}

void DrugComponent::insertNegativeEffect(GameEntity* entity){
	//empty method
}

void DrugComponent::insertParticleEffect(GameEntity* entity, double incr_particle_timer){
	//empty method
}