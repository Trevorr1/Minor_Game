#pragma once
namespace overdose {
	class ScheduleForRemovalFlag {
	private:
		bool m_scheduledForRemoval = false;
	public:
		void scheduleForRemoval();
		bool isScheduledForRemoval();

	};
}