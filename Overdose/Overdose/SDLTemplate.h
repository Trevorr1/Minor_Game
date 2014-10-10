#pragma once

#define SCRWIDTH	640
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
