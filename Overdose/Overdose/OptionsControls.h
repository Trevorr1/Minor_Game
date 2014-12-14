#pragma once
#include "Ilevel.h"
#include "GameEntityFactory.h"
namespace overdose {
	class OptionsControls : public ILevel
	{
	public:
		OptionsControls();
		virtual ~OptionsControls();
		void Init();
		bool isGameOver() { return false; }
	};
}