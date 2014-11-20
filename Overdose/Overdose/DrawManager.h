#pragma once

#include "surface.h"

class DrawManager
{
public:
	static DrawManager& getInstance();
	virtual ~DrawManager() { delete m_Level; delete m_Camera; }

	void setTargetSurface(Surface* aSurface) { m_Level = aSurface; }
	void createLevelSurface(int width, int height);
	void setTargetCameraSurface(Surface* aSurface) { m_Camera = aSurface; }

	void convertLevelToCamera(int xoffset, int yoffset);

	Surface* getLevelSurface() { return m_Level; }
	Surface* getCameraSurface() { return m_Camera; }

private:
	DrawManager() {}
	Surface* m_Level;
	Surface* m_Camera;
};

