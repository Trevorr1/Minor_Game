#pragma once
#include "Ilevel.h"
#include "GameEntityFactory.h"
namespace overdose {
	class OptionsGeneral : public ILevel
	{
	public:
		OptionsGeneral();
		virtual ~OptionsGeneral();
		void Init();
		bool isGameOver() { return false; }
	};
}