#include "Tile.h"

using namespace overdose;


Tile::Tile()
{
}


Tile::~Tile()
{
}

unsigned int Tile::getWorldPositionX()
{
	return m_WorldPositionX;
}

void Tile::setWorldPositionX(unsigned int posx)
{
	m_WorldPositionX = posx;
}

unsigned int Tile::getWorldPositionY()
{
	return m_WorldPositionY;
}

void Tile::setWorldPositionY(unsigned int posy)
{
	m_WorldPositionY = posy;
}

unsigned int Tile::getTileWidth()
{
	return m_Width;
}

unsigned int Tile::getTileHeight()
{
	return m_Height;
}
