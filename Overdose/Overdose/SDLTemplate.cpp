#include "SDLTemplate.h"

extern "C"
{
#include "glew.h" 
}
#include "gl.h"
#include "io.h"
#include <ios>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "SDL.h"
#include "SDL_syswm.h"
#include "wglext.h"
#include "game.h"
#include "surface.h"
#include "template.h"
#include "fcntl.h"

using namespace std;

PFNGLGENBUFFERSPROC glGenBuffers = 0;
PFNGLBINDBUFFERPROC glBindBuffer = 0;
PFNGLBUFFERDATAPROC glBufferData = 0;
PFNGLMAPBUFFERPROC glMapBuffer = 0;
PFNGLUNMAPBUFFERPROC glUnmapBuffer = 0;
typedef BOOL(APIENTRY *PFNWGLSWAPINTERVALFARPROC)(int);
PFNWGLSWAPINTERVALFARPROC wglSwapIntervalEXT = 0;
unsigned int framebufferTexID[2];
GLuint fbPBO[2];
unsigned char* framedata = 0;

static bool FULLSCREEN = false, firstframe = true;
double lastftime = 0;
LARGE_INTEGER lasttime, ticksPS;

SDL_Window *screen = 0;
Surface* surface = 0;
Game* game = 0;

SDLTemplate::SDLTemplate()
{
}


SDLTemplate::~SDLTemplate()
{
}

bool SDLTemplate::createFBtexture()
{
	//glGenTextures(2, framebufferTexID);
	if (glGetError()) return false;
	for (int i = 0; i < 2; i++)
	{
		glBindTexture(GL_TEXTURE_2D, framebufferTexID[i]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, SCRWIDTH, SCRHEIGHT, 0, GL_BGRA, GL_UNSIGNED_BYTE, NULL);
		glBindTexture(GL_TEXTURE_2D, 0);
		if (glGetError()) return false;
	}
	const int sizeMemory = 4 * SCRWIDTH * SCRHEIGHT;
	//glGenBuffers(2, fbPBO);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, fbPBO[0]);
	glBufferData(GL_PIXEL_UNPACK_BUFFER_ARB, sizeMemory, NULL, GL_STREAM_DRAW_ARB);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, fbPBO[1]);
	glBufferData(GL_PIXEL_UNPACK_BUFFER_ARB, sizeMemory, NULL, GL_STREAM_DRAW_ARB);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, 0);
	//glBindTexture(GL_TEXTURE_2D, framebufferTexID[0]);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, fbPBO[0]);
	//framedata = (unsigned char*)glMapBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, GL_WRITE_ONLY_ARB);
	if (!framedata) return false;
	memset(framedata, 0, SCRWIDTH * SCRHEIGHT * 4);
	return (glGetError() == 0);
}

bool SDLTemplate::init()
{
	fbPBO[0] = fbPBO[1] = -1;
	glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffersARB");
	glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBufferARB");
	glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferDataARB");
	glMapBuffer = (PFNGLMAPBUFFERPROC)wglGetProcAddress("glMapBufferARB");
	glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)wglGetProcAddress("glUnmapBufferARB");
	wglSwapIntervalEXT = (PFNWGLSWAPINTERVALFARPROC)wglGetProcAddress("wglSwapIntervalEXT");
	if ((!glGenBuffers) || (!glBindBuffer) || (!glBufferData) || (!glMapBuffer) || (!glUnmapBuffer)) return false;
	if (glGetError()) return false;
	glViewport(0, 0, SCRWIDTH, SCRHEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1, 0, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	if (!createFBtexture()) return false;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	if (wglSwapIntervalEXT) wglSwapIntervalEXT(0);
	QueryPerformanceFrequency(&ticksPS);
	surface = new Surface(SCRWIDTH, SCRHEIGHT, 0, SCRWIDTH);
	surface->InitCharset();
	return true;
}

void SDLTemplate::redirectIO()
{
	static const WORD MAX_CONSOLE_LINES = 500;
	int hConHandle;
	long lStdHandle;
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	FILE *fp;
	AllocConsole();
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),
		&coninfo);
	coninfo.dwSize.Y = MAX_CONSOLE_LINES;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),
		coninfo.dwSize);
	lStdHandle = (long)GetStdHandle(STD_OUTPUT_HANDLE);
	hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
	fp = _fdopen(hConHandle, "w");
	*stdout = *fp;
	setvbuf(stdout, NULL, _IONBF, 0);
	lStdHandle = (long)GetStdHandle(STD_INPUT_HANDLE);
	hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
	fp = _fdopen(hConHandle, "r");
	*stdin = *fp;
	setvbuf(stdin, NULL, _IONBF, 0);
	lStdHandle = (long)GetStdHandle(STD_ERROR_HANDLE);
	hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
	fp = _fdopen(hConHandle, "w");
	*stderr = *fp;
	setvbuf(stderr, NULL, _IONBF, 0);
	ios::sync_with_stdio();
}

void SDLTemplate::swap()
{
	static int index = 0;
	int nextindex;
	glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER_ARB);
	glBindTexture(GL_TEXTURE_2D, framebufferTexID[index]);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, fbPBO[index]);
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, SCRWIDTH, SCRHEIGHT, GL_BGRA, GL_UNSIGNED_BYTE, 0);
	nextindex = (index + 1) % 2;
	index = (index + 1) % 2;
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, fbPBO[nextindex]);
	framedata = (unsigned char*)glMapBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, GL_WRITE_ONLY_ARB);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(0.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(1.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(0.0f, 0.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	//SDL_GL_SwapBuffers();
	SDL_GL_SwapWindow(screen);
}

void SDLTemplate::initTemplate()
{
	redirectIO();
	printf("Initializing Overdose Engine.\n");
	SDL_Init(SDL_INIT_VIDEO);
	//SDL_SetVideoMode( SCRWIDTH, SCRHEIGHT, 32, SDL_OPENGL );
	//SDL_EnableKeyRepeat( 0, 0 );
	bool vbo = true;

	if (!init())
	{
		//SDL_SetVideoMode( SCRWIDTH, SCRHEIGHT, 32, SDL_HWSURFACE|SDL_DOUBLEBUF );
		screen = SDL_CreateWindow("Overdose",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCRWIDTH,
			SCRHEIGHT,
			SDL_WINDOW_OPENGL);
		SDL_Surface* s = SDL_GetWindowSurface(screen);
		surface = new Surface(SCRWIDTH, SCRHEIGHT, (Pixel*)s->pixels, s->pitch);
		surface->InitCharset();
		vbo = false;
		//SDL_WM_SetCaption( "Template - FALLBACK", NULL );
	}
	//else SDL_WM_SetCaption( "Template", NULL );
	else screen = SDL_CreateWindow("Overdose",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCRWIDTH,
		SCRHEIGHT,
		SDL_WINDOW_OPENGL);
	
	game = new Game();
	game->SetTarget(surface);
	float deltaTime = 0.0f;
	float timedifference = 0.0f;
	int thisTime = 0;
	int lastTime = 0;

	while (!m_exit)
	{
		//glViewport(0, 0, 300, 400);

		//glClearColor(0, 0, 0, 1);
		//glClear(GL_COLOR_BUFFER_BIT);

		//glMatrixMode(GL_PROJECTION);
		//glLoadIdentity();
		//glOrtho(0, 300, 0, 400, -1, 1); // gluOrtho2D is the most useless wrapper ever..., just put a -1, 1 as additional parameters to glOrtho

		//glMatrixMode(GL_MODELVIEW);
		//glLoadIdentity();

		//glShadeModel(GL_SMOOTH);

		thisTime = GetTickCount();
		timedifference = (float)(thisTime - lastTime);
		deltaTime = timedifference / 1000;
		lastTime = thisTime;

		if (vbo) // frame buffer swapping for VBO mode
		{
			swap();
			surface->SetBuffer((Pixel*)framedata);
		}
		else	 // frame buffer swapping for fall-back path
		{
			SDL_Surface* s = SDL_GetWindowSurface(screen);
			//SDL_UpdateRect( s, 0, 0, 0, 0 );
			SDL_UpdateWindowSurface(screen);
			framedata = (unsigned char*)s->pixels;
			surface->SetPitch(s->pitch / 4);
			surface->SetBuffer((Pixel*)framedata);
		}
		if (firstframe)
		{
			game->Init();
			firstframe = false;
		}

		game->Tick(deltaTime);
		
		// event loop
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
	
			int size;
			Uint8 *keyStates = const_cast<Uint8*>(SDL_GetKeyboardState(&size));

		



			game->KeyStates(keyStates, size);
			switch (event.type)
			{
			case SDL_QUIT:
				m_exit = true;
				break;
			case SDL_MOUSEMOTION:
				game->MouseMove(event.motion.x, event.motion.y);
				break;
			case SDL_MOUSEBUTTONUP:
				game->MouseUp(event.button.button);
				break;
			case SDL_MOUSEBUTTONDOWN:
				game->MouseDown(event.button.button);
				break;
			default:
				// more info on events in SDL: http://sdl.beuc.net/sdl.wiki/SDL_Event
				break;
			}
		}


		//Goodnight
		if (timedifference < m_desiredDeltaLoop){
			SDL_Delay(m_desiredDeltaLoop - timedifference);
		} 
		else{
			//SDL_Delay(1);
		}
	}
	delete game;
	surface->clearBuffer = false;
	delete surface;
	
	SDL_Quit();
}

void SDLTemplate::exit() {
	m_exit = true;
}