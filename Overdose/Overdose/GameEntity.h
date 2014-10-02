#pragma once
#include "stdafx.h"
#include "Component.h"

namespace overdose {
	class GameEntity
	{
	protected:
		float posX = 1.0, posY = 1.0, speedX = 1.0, speedY = 1.0;

	public:
		virtual void addComponent(Component &component);

		virtual void tick();

		float getPosX();
		float getPosY();
		float getSpeedX();
		float getSpeedY();

		void setSpeedX(float sx);
		void setSpeedY(float sy);
		void setPosX(float px);
		void setPosY(float py);

		GameEntity();

		~GameEntity();
	};


}