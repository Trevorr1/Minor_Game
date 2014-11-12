#pragma once

#include "surface.h"

namespace overdose
{
	class GameEntity;
	class Camera
	{
	public:
		Camera();
		virtual ~Camera();

		void Tick(Surface* aTarget);

		void setEntityFocus(GameEntity* aFocusEntity);
		GameEntity* getFocusEnity();

		unsigned int getPositionX();
		void setPositionX(unsigned int posx);

		unsigned int getPositionY();
		void setPositionY(unsigned int posy);

	private:
		GameEntity* m_FocusEntity;

		unsigned int m_CameraPositionX;
		unsigned int m_CameraPositionY;
	};
}


