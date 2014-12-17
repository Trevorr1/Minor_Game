#include <string>
#include "string.h"
#include "surface.h"
#include "stdlib.h"
#include "template.h"
#include "game.h"

#include "SDL.h"
#include <time.h>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
//#include <crtdbg.h>

using namespace Tmpl8;

//forward declarations
int convertFromGameEnum(int e);
int convertToGameEnum(int e);
bool check_collision(SDL_Rect &A, SDL_Rect &B);
void set_camera();
void set_tiles(Tile* tiles[]);
void put_tile(Tile *tiles[], int tileType);

/*******************************
********THESE ENMUS ARE UNFRIENDLY WITH OUR GAME ENUMS**********
********************************/
//The different tile sprites
int count = 0;
const int TILE_GRASS = 0;
const int TILE_MARIHUANA = 1;
const int TILE_SPEED = 2;
const int TILE_FLAG = 3;
const int TILE_WHITE = 4;

const int TILE_SPRITES = 5;

Surface* tilesAsset[TILE_SPRITES];

int currentTileType = TILE_GRASS;

//the camera
SDL_Rect camera = { 0, 0, SCRWIDTH, SCRHEIGHT };

bool check_collision(SDL_Rect &A, SDL_Rect &B)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	bottomA = A.y + A.h;

	//Calculate the sides of rect B
	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

void set_camera()
{
	//Mouse offsets
	int x = 0, y = 0;

	//Get mouse offsets
	SDL_GetMouseState(&x, &y);

	//Move camera to the left if needed
	if (x < TILE_WIDTH)
	{
		camera.x -= 1;
	}

	//Move camera to the right if needed
	if (x > SCRWIDTH - TILE_WIDTH)
	{
		camera.x += 1;
	}

	//Move camera up if needed
	if (y < TILE_WIDTH)
	{
		camera.y -= 1;
	}

	//Move camera down if needed
	if (y > SCRHEIGHT - TILE_WIDTH)
	{
		camera.y += 1;
	}

	//Keep the camera in bounds.
	if (camera.x < 0)
	{
		camera.x = 0;
	}
	if (camera.y < 0)
	{
		camera.y = 0;
	}
	if (camera.x > LEVEL_WIDTH - camera.w)
	{
		camera.x = LEVEL_WIDTH - camera.w;
	}
	if (camera.y > LEVEL_HEIGHT - camera.h)
	{
		camera.y = LEVEL_HEIGHT - camera.h;
	}
}

void set_tiles(Tile *tiles[])
{
	//The tile offsets
	int x = 0, y = 0;

	//Initialize the tiles
	for (int t = 0; t < TOTAL_TILES; t++)
	{
		int type = TILE_WHITE;
		//Put a floor tile
		tiles[t] = new Tile(x, y, type, tilesAsset[type]);

		//Move to next tile spot
		x += TILE_WIDTH;

		//If we've gone too far
		if (x >= LEVEL_WIDTH)
		{
			//Move back
			x = 0;

			//Move to the next row
			y += TILE_HEIGHT;
		}
	}
}

void put_tile(Tile *tiles[], int tileType)
{
	//Mouse offsets
	int x = 0, y = 0;

	//Get mouse offsets
	SDL_GetMouseState(&x, &y);

	//Adjust to camera
	x += camera.x;
	y += camera.y;

	//Go through tiles
	for (int t = 0; t < TOTAL_TILES; t++)
	{
		//Get tile's collision box
		SDL_Rect box = tiles[t]->get_box();

		//If the mouse is inside the tile
		if ((x > box.x) && (x < box.x + box.w) && (y > box.y) && (y < box.y + box.h))
		{
			//Get rid of old tile
			delete tiles[t];

			//Replace it with new one
			tiles[t] = new Tile(box.x, box.y, tileType, tilesAsset[tileType]);
		}
	}
}

Game::~Game()
{
	for (int i = 0; i < TILE_SPRITES; i++)
	{
		delete tilesAsset[i];
	}

	//Free the tiles
	for (int t = 0; t < TOTAL_TILES; t++)
	{
		delete tiles[t];
	}

	//_CrtDumpMemoryLeaks();
}

void Game::Init()
{
	//Validate Dimensions
	if (LEVEL_WIDTH % TILE_WIDTH != 0){
		printf("ERROR: WRONG LEVEL WIDTH \n");
	}
	if (LEVEL_HEIGHT % TILE_HEIGHT != 0){
		printf("ERROR: WRONG LEVEL HEIGHT \n");
	}
	const int TOTAL_TILES = (LEVEL_WIDTH / TILE_WIDTH) * (LEVEL_HEIGHT / TILE_HEIGHT);

	tilesAsset[TILE_GRASS] = new Surface("assets/tiles/grass.png");
	tilesAsset[TILE_MARIHUANA] = new Surface("assets/tiles/marihuana32x32.png");
	tilesAsset[TILE_SPEED] = new Surface("assets/tiles/speed32x32.png");
	tilesAsset[TILE_FLAG] = new Surface("assets/tiles/flag.png");
	tilesAsset[TILE_WHITE] = new Surface("assets/tiles/white.png");

	for (int i = 0; i < TOTAL_TILES; i++)
	{
		tiles[i] = nullptr;
	}

	set_tiles(tiles);

	load();
}

void Game::Tick( float a_DT )
{
	m_Screen->Clear(0x000000);
	int x, y;

	SDL_GetMouseState(&x, &y);

	set_camera();

	for (int i = 0; i < TOTAL_TILES; i++)
	{
		if (tiles[i] != nullptr)
		{
			tiles[i]->show(m_Screen);
		}	
	}
}

void Game::KeyDown(unsigned int code)
{
	//printf("Code %d\n", code);
	if (code == 22)
	{
		//save here pls
		//maybe sound feedback?
		save();
	}
}

void Game::save()
{
	std::ofstream output_file(LEVEL_FILE_PATH + std::to_string(LEVEL_NAME) + ".txt");
	for (int i = 0; i < TOTAL_TILES; i++){
		Tile* tile = tiles[i];

		//TODO: Make new classes for each specific tile, and set the specific increments there
		int xIncrement = 0;
		int yIncrement = 0;
		if (tile->get_type() == TILE_FLAG){
			yIncrement -= 2 * TILE_HEIGHT + 15;
			xIncrement += 4;
		}

		if (tile->get_type() != TILE_WHITE){
			std::string type = std::to_string(convertToGameEnum(tile->get_type())).c_str();
			std::string x = std::to_string((int)tile->get_box().x + xIncrement).c_str();
			std::string y = std::to_string((int)tile->get_box().y + yIncrement).c_str();
			output_file << type << " " << x << (" ") << y << "\n";
		}
	
	}
}

void Game::load()
{
	std::string line;
	int eGameEntity;
	int x;
	int y;

	const std::string textfile(LEVEL_FILE_PATH + std::to_string(LEVEL_NAME) + ".txt");

	if (!std::ifstream(textfile))
	{
		return;
	}

	// input file stream, opent textfile voor lezen
	std::ifstream input_file(textfile);

	while (getline(input_file, line)){
		if ((line[0] == '/') &&
			(line[1] == '/')){
			continue;
		}
		else if (line == ""){
			continue;
		}

		std::istringstream iss(line);
		std::vector<std::string> tokens{ std::istream_iterator < std::string > {iss}, std::istream_iterator < std::string > {} };
		eGameEntity = convertFromGameEnum(atoi(tokens.at(0).c_str()));
		x = atoi(tokens.at(1).c_str());
		y = atoi(tokens.at(2).c_str());

		//Todo: Fix this ugly code
		if (eGameEntity == TILE_FLAG){
			y += 2 * TILE_HEIGHT + 15;
			x -= 4;
		}

		int row = (int)y / 32; //Todo: Check if out of bounce
		int column = (int)x / 32; //Todo: Check if out of bounce
		int t = row * (LEVEL_WIDTH / TILE_WIDTH) + column; //Todo: Check if out of bounce

		delete tiles[t];
		tiles[t] = new Tile(x, y, eGameEntity, tilesAsset[eGameEntity]);
	}
}

void Game::MouseDown(unsigned int button)
{
	printf("code: %d\n", button);

	if (button == 1)
	{
		//Put the tile
		put_tile(tiles, currentTileType);
	}

	if (button == 3)
	{
		put_tile(tiles, TILE_WHITE);
	}
}

void Game::MouseWheel(unsigned int button)
{
	if (button < 0)
	{
		currentTileType++;

		if (currentTileType > TILE_FLAG) //was tile_ice
		{
			currentTileType = TILE_GRASS;
		}
	}
	else
	{
		currentTileType--;

		if (currentTileType < TILE_GRASS)
		{
			currentTileType = TILE_FLAG;
		}
	}

	//printf("code: %d\n", button);
}

int convertToGameEnum(int e)
{
	int retval;

	switch (e)
	{
	case TILE_GRASS:
		retval = 10;
		break;
	case TILE_MARIHUANA:
		retval = 8;
		break;
	case TILE_SPEED:
		retval = 7;
		break;
	case TILE_FLAG:
		retval = 11;
		break;
	default:
		retval = e;
		break;
	}

	return retval;
}

int convertFromGameEnum(int e)
{
	int retval;

	switch (e)
	{
	case 10:
		retval = TILE_GRASS;
		break;
	case 8:
		retval = TILE_MARIHUANA;
		break;
	case 7:
		retval = TILE_SPEED;
		break;
	case 11:
		retval = TILE_FLAG;
		break;
	default:
		retval = e;
		break;
	}

	return retval;
}


Tile::Tile(int x, int y, int tileType, Surface* s)
{
    //Get the offsets
    box.x = x;
    box.y = y;
    
    //Set the collision box
    box.w = TILE_WIDTH;
    box.h = TILE_HEIGHT;
    
    //Get the tile type
    type = tileType;

	//init surface 
	tile = s;
}

void Tile::show(Surface* target)
{
    //If the tile is on screen
    if( check_collision( camera, box ) == true )
    {
        //Show the tile
		tile->CopyTo(target, box.x - camera.x, box.y - camera.y);
		//apply_surface( box.x - camera.x, box.y - camera.y, tileSheet, screen, &clips[ type ] );    
    }
}    

int Tile::get_type()
{
    return type;
}

SDL_Rect &Tile::get_box()
{
    return box;
}