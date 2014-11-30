#pragma once
#include "GameEntity.h"
namespace overdose {

	class TextGameEntity : public GameEntity {
	private:
		char* m_Text;
	public:
		TextGameEntity(char* contents);
		virtual void tick(float dt);
	};
}