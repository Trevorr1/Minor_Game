#include "SoundManager.h"
#include <iostream>


using namespace overdose;

SoundManager* SoundManager::_instance = nullptr;

SoundManager* SoundManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new SoundManager();
	}
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
	Mix_FreeChunk(gHigh);
	Mix_FreeChunk(gMedium);
	Mix_FreeChunk(gLow);
	Mix_FreeChunk(gDeath);
	gHigh = NULL;
	gMedium = NULL;
	gLow = NULL;
	gDeath = NULL;

	//Free the music
	Mix_FreeMusic(gMusicMainMenu);
	gMusicMainMenu = NULL;

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

	//Load sound effects
	gHigh = Mix_LoadWAV("assets/sfx/high.wav");
	if (gHigh == NULL)
	{
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	gMedium = Mix_LoadWAV("assets/sfx/medium.wav");
	if (gMedium == NULL)
	{
		printf("Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	gLow = Mix_LoadWAV("assets/sfx/low.wav");
	if (gLow == NULL)
	{
		printf("Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	gDeath = Mix_LoadWAV("assets/sfx/scream.wav");
	if (gDeath == NULL)
	{
		printf("Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	return success;
}


void SoundManager::PlayMusic(eMusic music){
	
	Mix_Music* sound = nullptr;
	switch (music)
	{
	case MainMenu:
		sound = gMusicMainMenu;
		break;

	case Street:
		sound = gMusicStreet;
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
		//Play high sound effect
		case High:
			Mix_PlayChannel(-1, gHigh, 0);
			break;

		//Play medium sound effect
		case Medium:
			Mix_PlayChannel(-1, gMedium, 0);
			break;

		//Play low sound effect
		case Low:
			Mix_PlayChannel(-1, gLow, 0);
			break;

		//Play Death sound effect
		case Death:
			Mix_PlayChannel(-1, gDeath, 0);
			break;
	}
}



