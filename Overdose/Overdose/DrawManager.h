#pragma once

#include "surface.h"

class DrawManager
{
public:
	static DrawManager& getInstance();
	virtual ~DrawManager() {}

	void setTargetSurface(Surface* aSurface) { m_Surface = aSurface;  }
	Surface* getSurface() { return m_Surface;  }

private:
	DrawManager() {}
	Surface* m_Surface;
};

