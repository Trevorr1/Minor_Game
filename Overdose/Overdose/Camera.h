#pragma once

#include "surface.h"
#include "Tile.h"

namespace overdose
{
	class GameEntity;
	class Camera
	{
	public:
		Camera();
		virtual ~Camera();

		void Tick();

		void setTileMap(int tileMap[], int size);
		void setTileAssets(Tile* tileAssets);		

		void setEntityFocus(GameEntity* aFocusEntity);
		GameEntity* getFocusEnity();

		unsigned int getPositionX();
		void setPositionX(unsigned int posx);

		unsigned int getPositionY();
		void setPositionY(unsigned int posy);

	private:
		GameEntity* m_FocusEntity;

		int *m_TileMap2;
		int m_TileMap[32*12];
		Tile* m_TileAssets;

		unsigned int m_WorldCameraPositionX;
		unsigned int m_WorldCameraPositionY;
	};
}


