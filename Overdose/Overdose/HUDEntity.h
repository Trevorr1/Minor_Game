#pragma once
#include "GameEntity.h"
#include "DrawComponent.h"

namespace overdose{

	class HUDEntity	:
		public GameEntity
	{
	public:
		HUDEntity(int x, int y);
		virtual ~HUDEntity();
	protected:
		DrawComponent* m_DrawComponent;
	};
}// namespace overdose

