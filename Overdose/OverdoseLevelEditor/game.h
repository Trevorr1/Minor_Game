#pragma once

#include "SDL.h"

//level name stuff
const int LEVEL_NAME = 4;
const std::string LEVEL_FILE_PATH = "../Overdose/assets/levels/level";

//The dimensions of the level
const int LEVEL_WIDTH = 1920;
const int LEVEL_HEIGHT = 480;

//tile constants
const int TILE_WIDTH = 32;
const int TILE_HEIGHT = 32;
const int TOTAL_TILES = (LEVEL_WIDTH / TILE_WIDTH) * (LEVEL_HEIGHT / TILE_HEIGHT);

namespace Tmpl8 {

	class Surface;
	class Tile
	{
	public:
		//Initializes the variables
		Tile(int x, int y, int tileType, Surface* s);

		//Shows the tile
		void show(Surface* target);

		//Get the tile type
		int get_type();

		//Get the collision box
		SDL_Rect& get_box();
	private:
		//The attributes of the tile
		SDL_Rect box;

		//art asset
		Surface* tile;

		//The tile type
		int type;
	};

class Surface;
class Sprite;
class Game
{
public:
	~Game();
	void SetTarget( Surface* a_Surface ) { m_Screen = a_Surface; }
	void Init();
	void Tick( float a_DT );
	//ui stuff
	void showArtHud();
	void showCurrentSelectedArtAsset();
	void showScrollingBorders();
	//fileio stuff
	void save();
	void load();
	void KeyDown(unsigned int code);
	void KeyUp( unsigned int code ) {}
	void MouseMove(unsigned int x, unsigned int y) {}
	void MouseUp( unsigned int button ) {}
	void MouseDown(unsigned int button);
	void MouseWheel(unsigned int button);
private:
	Tile* tiles[TOTAL_TILES];
	Surface* m_Screen;
};

}; // namespace Tmpl8