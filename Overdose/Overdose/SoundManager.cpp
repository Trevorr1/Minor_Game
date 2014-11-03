#include "SoundManager.h"
#include <iostream>


using namespace overdose;

SoundManager &SoundManager::getInstance()
{
	static SoundManager _instance;
	return _instance;
}

SoundManager::SoundManager()
{
	if (init()){
		std::cout << "Succesfully initialised SoundManager" << std::endl;
		if (loadMedia())
		{
			std::cout << "Succesfully loaded media files" << std::endl;
		}
		else
		{
			std::cout << "Failed to load media files" << std::endl;
		}
	}
	else{
		std::cout << "Failed to initialise SoundManager" << std::endl;
	}
}


SoundManager::~SoundManager()
{
	//Free the sound effects
	Mix_FreeChunk(gClick);
	Mix_FreeChunk(gDeath);
	Mix_FreeChunk(gGameOver);
	Mix_FreeChunk(gPartyHorn);

	gClick = NULL;
	gDeath = NULL;
	gGameOver = NULL;
	gPartyHorn = NULL;

		//Free the music
	Mix_FreeMusic(gMusicMainMenu);
	Mix_FreeMusic(gMusicStreet);
	Mix_FreeMusic(gPeople);
	gMusicMainMenu = NULL;
	gMusicStreet = NULL;
	gPeople = NULL;

	//Quit SDL subsystems
	Mix_Quit();
}



bool SoundManager::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	return success;
}

bool SoundManager::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load music
	gMusicMainMenu = Mix_LoadMUS("assets/music/MainMenu.wav");
	if (gMusicMainMenu == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	gMusicStreet = Mix_LoadMUS("assets/music/Street.wav");
	if (gMusicStreet == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	gPeople = Mix_LoadMUS("assets/sfx/people.wav");
	if (gPeople == NULL)
	{
		printf("Failed to load people sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	//Load sound effects
	gClick = Mix_LoadWAV("assets/sfx/click.wav");
	if (gDeath == NULL)
	{
		printf("Failed to load death sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	gDeath = Mix_LoadWAV("assets/sfx/scream.wav");
	if (gDeath == NULL)
	{
		printf("Failed to load death sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	gGameOver = Mix_LoadWAV("assets/sfx/GameOver.wav");
	if (gGameOver == NULL)
	{
		printf("Failed to load gameover sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	gPartyHorn = Mix_LoadWAV("assets/sfx/party-horn.wav");
	if (gPartyHorn == NULL)
	{
		printf("Failed to load party-horn sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}



	return success;
}


void SoundManager::PlayMusic(eMusic music){
	
	Mix_Music* sound = nullptr;
	switch (music)
	{
	case MainMenuTheme:
		sound = gMusicMainMenu;
		break;

	case Street:
		sound = gMusicStreet;
		break;

	case People:
		sound = gPeople;
		break;
	}

	//If sound found:
	if (sound != nullptr){

		StopMusic();

		//If there is no music playing
		if (Mix_PlayingMusic() == 0)
		{
			//Play the music
			Mix_PlayMusic(sound, -1);
		}
		//If music is being played
		else
		{
			//If the music is paused
			if (Mix_PausedMusic() == 1)
			{
				//Resume the music
				Mix_ResumeMusic();
			}
			//If the music is playing
			else
			{
				//Pause the music
				Mix_PauseMusic();
			}
		}
	}
}

void SoundManager::StopMusic(){
	Mix_HaltMusic();
}

void SoundManager::PlaySound(eSound sound){
	
	switch (sound)
	{
		case Click:
			Mix_PlayChannel(-1, gClick, 0);
			break;
		case Death:
			Mix_PlayChannel(-1, gDeath, 0);
			break;
		case GameOverSound:
			Mix_PlayChannel(-1, gGameOver, 0);
			break;
		case PartyHorn:
			Mix_PlayChannel(-1, gPartyHorn, 0);
			break;
	}
}



