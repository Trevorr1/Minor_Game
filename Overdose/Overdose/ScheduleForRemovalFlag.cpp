#include "ScheduleForRemovalFlag.h"

using namespace overdose;

bool ScheduleForRemovalFlag::isScheduledForRemoval() {
	return m_scheduledForRemoval;
}

void ScheduleForRemovalFlag::scheduleForRemoval() {
	m_scheduledForRemoval = true;
}