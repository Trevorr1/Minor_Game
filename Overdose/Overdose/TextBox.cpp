#include "TextBox.h"
#include "template.h"
#include "surface.h"
#include "freeimage.h"

using namespace overdose;

TextBox::TextBox(SDL_Surface* screen, int posX, int posY, int width, int height) {
	this->screen = screen;
	this->active = false;
	this->cursor = false;
	this->box.x = posX;
	this->box.y = posY;
	this->box.w = width;
	this->box.h = height;
	int tamFont = height - 2;
	this->font = TTF_OpenFont("Arial.ttf", tamFont);
	SDL_Color textColor = { 0, 0, 0 };
	this->textColor = textColor;
	this->selected = false;
	this->showText = "";
}

TextBox::TextBox(SDL_Surface* screen, int posX, int posY, int width, int height, std::string showText) {
	this->screen = screen;
	this->active = false;
	this->selected = false;
	this->box.x = posX;
	this->box.y = posY;
	this->box.w = width;
	this->box.h = height;
	this->font = TTF_OpenFont("Arial.ttf", TAM_FONT);
	SDL_Color textColor = { 0, 0, 0 };
	this->textColor = textColor;
	this->showText = showText;
}

void TextBox::setText(std::string text){
	this->showText = text;
}

std::string TextBox::getText(void){
	return this->showText;
}

void TextBox::setSelected(bool select){
	this->selected = select;
}

void TextBox::clearBox(){
	this->showText.clear();
}

bool TextBox::drawBox() {
	if (this->selected)
		return SDL_FillRect(this->screen, &this->box, CYAN);
	else
		return SDL_FillRect(this->screen, &this->box, WHITE);
}

bool TextBox::draw() {
	this->drawBox();
	this->drawText();
	return true;
}

bool TextBox::drawText(){
	bool result;
	this->drawBox();
	std::string display = "";
	display = this->showText;
	SDL_Surface* message = NULL;
	message = TTF_RenderText_Solid(this->font, display.c_str(), this->textColor);
	if (message != NULL)
		this->textWidth = message->w;
	SDL_Rect tmp = this->box;
	SDL_Rect tmp2;
	tmp.x += BEGIN_SPACE;
	//Check width of the renderized text to show compared with box width.
	if (message != NULL){
		tmp2 = message->clip_rect;
		int dif = tmp2.w - this->box.w;
		if (dif >= -END_SPACE){
			tmp2.x += dif + END_SPACE;
			tmp2.w = tmp.w;
		}
		result = SDL_BlitSurface(message, &tmp2, this->screen, &tmp);
	}
	else
		result = SDL_BlitSurface(message, NULL, this->screen, &tmp);
	if (this->active){
		if (message != NULL){
			this->drawCursor(tmp.x + tmp.w);
		}
		else
			this->drawCursor(tmp.x);
	}
	SDL_FreeSurface(message);
	return result;
}

void TextBox::drawCursor(int pos){
	Draw_Line(this->screen, pos, this->box.y + 1, pos, this->box.y + this->box.h - 1, BLACK);
}


bool TextBox::isClicked(SDL_Event* e){
	if (e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT) {
		int x = e->button.x;
		int y = e->button.y;
		if (x < this->box.w + this->box.x && x > this->box.x && y < this->box.h + this->box.y && y > this->box.y) {
			return  true;
		}
		else {
			return  false;
		}
	}
	else
		return false;
}

void TextBox::handleEvent(SDL_Event* ev) {
	//If left click the textbox gets active for input.
	if (ev->type == SDL_MOUSEBUTTONDOWN && ev->button.button == SDL_BUTTON_LEFT) {
		int x = ev->button.x;
		int y = ev->button.y;
		if (x < this->box.w + this->box.x && x > this->box.x && y < this->box.h + this->box.y && y > this->box.y) {
			this->active = true;
		}
		else {
			this->active = false;
		}
	}
	else if (ev->type == SDL_KEYDOWN && this->active) {
		//If keydown and the box is active read char and write.
		char c = (char)ev->key.keysym.sym;
		if (c >= 'a' && c <= 'z') {
			SDLMod m = ev->key.keysym.mod;
			c = (m & KMOD_CAPS) || (m & KMOD_SHIFT) ? toupper((char)ev->key.keysym.sym) : (char)ev->key.keysym.sym;
			this->showText += c;
		}
		else if ((c <= '1' || c >= '0') && ev->key.keysym.sym != SDLK_LSHIFT && ev->key.keysym.sym != SDLK_RSHIFT && ev->key.keysym.sym != SDLK_RETURN) {
			if (ev->key.keysym.mod & KMOD_SHIFT) {
				switch (c) {
				case '1': c = '!'; break;
				case '2': c = '"'; break;
				case '3': c = '£'; break;
				case '4': c = '$'; break;
				case '5': c = '%'; break;
				case '6': c = '^'; break;
				case '7': c = '&'; break;
				case '8': c = '*'; break;
				case '9': c = '('; break;
				case '0': c = ')'; break;
				case '-': c = '_'; break;
				case '=': c = '+'; break;
				case '[': c = '{'; break;
				case ']': c = '}'; break;
				case ';': c = ':'; break;
				case '\'': c = '@'; break;
				case '#': c = '~'; break;
				case ',': c = '<'; break;
				case '.': c = '>'; break;
				case '/': c = '?'; break;
				default: break;
				}
			}
			this->showText += c;
		} if (ev->key.keysym.sym == SDLK_BACKSPACE) {
			this->showText = this->showText.substr(0, this->showText.length() - 2);
		}

		this->drawText();
	}
}



TextBox::~TextBox(){
}
