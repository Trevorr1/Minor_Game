#pragma once

#include "surface.h"

class DrawManager
{
public:
	static DrawManager* getInstance();
	virtual ~DrawManager() { instanceFlag = false; }

	void setTargetSurface(Surface* aSurface) { m_Surface = aSurface;  }
	Surface* getSurface() { return m_Surface;  }

private:
	DrawManager() {}
	static bool instanceFlag;
	static DrawManager* single;
	Surface* m_Surface;
};

