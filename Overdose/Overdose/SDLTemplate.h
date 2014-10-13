#pragma once

#define SCRWIDTH	940
#define SCRHEIGHT	480

	class SDLTemplate
	{
	public:
		SDLTemplate();
		~SDLTemplate();

		bool createFBtexture();
		bool init();
		void redirectIO();
		void swap();

		void initTemplate();
	};
