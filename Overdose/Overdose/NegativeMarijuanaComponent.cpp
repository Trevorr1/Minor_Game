#include "NegativeMarijuanaComponent.h"

using namespace overdose;

NegativeMarijuanaComponent::NegativeMarijuanaComponent()
{
	drug_speedX = 1.0f;
	drug_effect_ms = 1000 * 4;

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
	buffer = NULL;
	surfaceOriginal->SetBuffer(bufferNew);
}


NegativeMarijuanaComponent::~NegativeMarijuanaComponent()
{
	printf("deleted NegativeMarijuanaComponent \n");
	surfaceOriginal->SetBuffer(bufferOld);
	bufferOld = NULL;
	
	//delete bufferNew; //MEMORYLEAK: Waarom werkt dit niet? error: nBlockUse.
	//Buffer vrij maken daarna NULL werkt.
	_aligned_free(bufferNew);
	bufferNew = NULL;
}

void NegativeMarijuanaComponent::tick(float dt, GameEntity *entity) {
	DrugComponent::tick(dt, entity);
}

void NegativeMarijuanaComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}

float NegativeMarijuanaComponent::getDrugSpeed_X(){
	return drug_speedX;
}

int NegativeMarijuanaComponent::getDrugEffectMs(){
	return drug_effect_ms;
}

std::string NegativeMarijuanaComponent::getComponentID(){
	return "NegativeSpeedDrugComponent";
}
