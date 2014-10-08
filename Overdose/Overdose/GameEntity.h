#pragma once
#include "stdafx.h"
#include "Enum.h"
#include "Component.h"

namespace overdose {
	class Component;
	class GameEntity
	{
	protected:
		float posX = 1.0, posY = 1.0, speedX = 1.0, speedY = 1.0;
		int width = 0, height = 0;
		eGameEntity m_EntityEnum;
		bool isAlive = true;

	public:
		virtual void addComponent(Component &component);

		virtual void tick();

		float getPosX();
		float getPosY();
		float getSpeedX();
		float getSpeedY();

		float getPosition(int index); // voor bsp tree

		int getWidth();
		int getHeight();

		eGameEntity getEnum();

		void setSpeedX(float sx);
		void setSpeedY(float sy);
		void setPosX(float px);
		void setPosY(float py);

		void setCollided();

		GameEntity();
		GameEntity(eGameEntity entityEnum);

		~GameEntity();
	};


}