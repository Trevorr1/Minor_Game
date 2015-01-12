#include "NegativeMarijuanaComponent.h"

using namespace overdose;

NegativeMarijuanaComponent::NegativeMarijuanaComponent()
{
	drug_speedX = 1.0f;
	drug_effect_ms = 1000 * 6;

	surfaceOriginal = getSurface();
	Pixel* buffer = surfaceOriginal->GetBuffer();

	bufferOld = (Pixel*)_aligned_malloc(surfaceOriginal->GetWidth() * surfaceOriginal->GetHeight() * sizeof(Pixel), 64);
	bufferNew = (Pixel*)_aligned_malloc(surfaceOriginal->GetWidth() * surfaceOriginal->GetHeight() * sizeof(Pixel),64);

	for (int i = 0; i < surfaceOriginal->GetWidth() * surfaceOriginal->GetHeight(); i++){
		//buffer[i] = (255 - buffer[i]); //buffer[i] = (255-buffer[i]) & 0xFF; //0x6A9342

		////extra pixel manipulation
		//if (i > surfaceOriginal->GetWidth() && i< surfaceOriginal->GetWidth() * 100){
		//	buffer[i] = (255 - buffer[i]) & 0xFF;
		//}

		bufferOld[i] = buffer[i];
		bufferNew[i] = (255 - buffer[i]);
	}
	buffer = nullptr;
	surfaceOriginal->SetBuffer(bufferNew);
}


NegativeMarijuanaComponent::~NegativeMarijuanaComponent()
{
	printf("deleted NegativeMarijuanaComponent \n");
 	if (getLevel() == LevelManager::getInstance().getCurrentLevel()){
		surfaceOriginal->SetBuffer(bufferOld);
		_aligned_free(bufferNew);//Buffer vrij maken
	}

	bufferOld = nullptr;
	bufferNew = nullptr;
}


void NegativeMarijuanaComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}


void NegativeMarijuanaComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {}

float NegativeMarijuanaComponent::getDrugSpeed_X(){
	return drug_speedX;
}

int NegativeMarijuanaComponent::getDrugEffectMs(){
	return drug_effect_ms;
}

std::string NegativeMarijuanaComponent::getComponentID(){
	return "NegativeSpeedDrugComponent";
}

void NegativeMarijuanaComponent::insertParticleEffect(GameEntity* entity, double incr_particle_timer){
	entity->delayedAddComponent(new ParticleComponent(SadFace, 0.1, incr_particle_timer / 1000, 0.1));
}
