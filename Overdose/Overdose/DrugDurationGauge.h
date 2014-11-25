#pragma once
#include "HUDEntity.h"
#include <algorithm>
#define FULL 100
namespace overdose {

	class DrugDurationGauge :
		public HUDEntity
	{
	public:
		enum eDrugGaugeState {Gauge_Fill, Gauge_Empty, Gauge_Idle};
		DrugDurationGauge(int x, int y);
		virtual ~DrugDurationGauge();

		void tick(float dt);

		void setGaugeValue(float value) { m_GaugeValue = value; }

		void setState(eDrugGaugeState state) { m_State = state; }

	private:
		float m_GaugeValue;
		Surface* m_Bar;
		eDrugGaugeState m_State;
	};
}
