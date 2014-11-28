#pragma once
#include "GameEntity.h"
#include "surface.h"

namespace overdose
{
	class Tile : public GameEntity
	{
	public:
		Tile();
		virtual ~Tile();

		unsigned int getWorldPositionX();
		void setWorldPositionX(unsigned int posx);

		unsigned int getWorldPositionY();
		void setWorldPositionY(unsigned int posy);

		unsigned int getTileWidth();
		unsigned int getTileHeight();

	private:
		unsigned int m_WorldPositionX;
		unsigned int m_WorldPositionY;

		unsigned int m_Width;
		unsigned int m_Height;
	};
}

