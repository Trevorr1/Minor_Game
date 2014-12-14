#pragma once
#include "Ilevel.h"
#include "GameEntityFactory.h"
namespace overdose {
	class OptionsDrugs : public ILevel
	{
	public:
		OptionsDrugs();
		virtual ~OptionsDrugs();
		void Init();
		bool isGameOver() { return false; }
	};
}