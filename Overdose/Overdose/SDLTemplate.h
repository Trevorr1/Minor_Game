#pragma once

#include "math.h"
#include "stdlib.h"
#include "emmintrin.h"
#include "stdio.h"
#include "windows.h"

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
