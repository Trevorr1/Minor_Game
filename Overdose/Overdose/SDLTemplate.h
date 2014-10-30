#pragma once

#define SCRWIDTH	940
#define SCRHEIGHT	480
#include <chrono>
#include <thread>

	class SDLTemplate
	{
	private:
		int m_desiredFPS = 30;
		long m_desiredDeltaLoop = 1000  / m_desiredFPS;
	public:
		SDLTemplate();
		~SDLTemplate();

		bool createFBtexture();
		bool init();
		void redirectIO();
		void swap();

		void initTemplate();
	};
