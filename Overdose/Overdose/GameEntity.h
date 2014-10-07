#pragma once
#include "stdafx.h"
#include "Component.h"

namespace overdose {
	class Component;
	class GameEntity
	{
	protected:
		float posX = 1.0, posY = 1.0, speedX = 1.0, speedY = 1.0;
		int width = 0, height = 0;

	public:
		virtual void addComponent(Component &component);

		virtual void tick();

		float getPosX();
		float getPosY();
		float getSpeedX();
		float getSpeedY();

		int getWidth();
		int getHeight();

		void setSpeedX(float sx);
		void setSpeedY(float sy);
		void setPosX(float px);
		void setPosY(float py);

		float getPosition(int index);

		GameEntity();

		~GameEntity();
	};


}