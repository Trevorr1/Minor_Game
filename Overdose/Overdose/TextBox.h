#pragma once
#include "stdafx.h"
#include "SDL.h"

#define TAM_FONT 18
//Space between last character rendered and end of textbox, 
//values over or equal to 5 recommended.
#define END_SPACE 5
//Space between first character rendered and beginning of textbox, 
//values over or equal to 5 recommended.
#define BEGIN_SPACE 5
//Colors
#define CYAN 0x99FFCC
#define BLACK 0x000000
#define WHITE 0xFFFFFF

namespace overdose {
	class TextBox {
	private:
		SDL_Rect box;
		SDL_Surface* screen;
		TTF_Font* font;
		SDL_Color textColor;
		int textWidth;
		bool active, cursor;
		bool selected;
		std::string showText;
	public:
		TextBox(SDL_Surface* screen, int posX, int posY, int width, int height);
		TextBox(SDL_Surface* screen, int posX, int posY, int width, int height, std::string text);
		bool drawText(void);
		void handleEvent(SDL_Event* event);
		void setSelected(bool select);
		bool drawBox(void);
		bool draw(void);
		void setText(std::string t);
		std::string getText(void);
		void clearBox();

		void drawCursor(int pos);
		bool isClicked(SDL_Event* event);
		~TextBox(void);

	};
}
