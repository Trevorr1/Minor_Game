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
	Mix_FreeChunk(gOuch);
	Mix_FreeChunk(gPickUp);

	gClick = NULL;
	gDeath = NULL;
	gGameOver = NULL;
	gPartyHorn = NULL;
	gOuch = NULL;
	gPickUp = NULL;

	//Free the music
	Mix_FreeMusic(gMusicMainMenu);
	Mix_FreeMusic(gMusicStreet);
	Mix_FreeMusic(gPeople);
	Mix_FreeMusic(gBossFight);
	gMusicMainMenu = NULL;
	gMusicStreet = NULL;
	gPeople = NULL;
	gBossFight = NULL;


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
	gMusicMainMenu = Mix_LoadMUS("assets/music/MainMenu2.mp3");
	if (gMusicMainMenu == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	gMusicStreet = Mix_LoadMUS("assets/music/Street.mp3");
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

	gBossFight = Mix_LoadMUS("assets/music/abyss.mp3");
	if (gBossFight == NULL)
	{
		printf("Failed to load bossfight sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	//Load sound effects
	gClick = Mix_LoadWAV("assets/sfx/click.wav");
	if (gClick == NULL)
	{
		printf("Failed to load click sound effect! SDL_mixer Error: %s\n", Mix_GetError());
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

	gOuch = Mix_LoadWAV("assets/sfx/ouch.wav");
	if (gOuch == NULL)
	{
		printf("Failed to load ouch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	gPickUp = Mix_LoadWAV("assets/sfx/coin.wav");
	if (gOuch == NULL)
	{
		printf("Failed to load pick - up sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	gGunshot = Mix_LoadWAV("assets/sfx/gunshot.wav");
	if (gGunshot == NULL)
	{
		printf("Failed to load gunshot sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	gCloseCombat = Mix_LoadWAV("assets/sfx/closecombat.wav");
	if (gCloseCombat == NULL)
	{
		printf("Failed to load closecombat sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}


	gSiren = Mix_LoadWAV("assets/sfx/siren.wav");
	if (gSiren == NULL)
	{
		printf("Failed to load siren sound effect! SDL_mixer Error: %s\n", Mix_GetError());
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
	case BossFight:
		sound = gBossFight;
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

bool SoundManager::isPlaying() {
	return Mix_PlayingMusic() != 0;
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
	case Ouch:
		Mix_PlayChannel(-1, gOuch, 0);
		break;
	case PickUp:
		Mix_PlayChannel(-1, gPickUp, 0);
		break;
	case CloseCombat:
		Mix_PlayChannel(-1, gCloseCombat, 0);
		break;
	case Gunshot:
		Mix_PlayChannel(-1, gGunshot, 0);
		break;
	case Siren:
		Mix_PlayChannel(-1, gSiren, 0);
		break;

	}
}

void SoundManager::PlaySound1(eSound sound) {
	PlaySound(sound);
}


void SoundManager::ToggleMute(){
	m_mute = (m_mute) ? false : true;
	SetVolume();
}

void SoundManager::ToggleMute(bool mute){
	m_mute = mute;
	SetVolume();
}

void SoundManager::SetVolume(){
	if (!m_mute){
		Mix_Volume(-1, MIX_MAX_VOLUME);//Set all sound volume to max (128 i believe)
		Mix_ResumeMusic();//Resume music 
		//std::cout << "Unmuted" << std::endl;
	}
	else{
		Mix_Volume(-1, 0);//Reduce all sound volume to 0 (sounds will be played, but won't be heard)
		Mix_PauseMusic();//Pause music
		//std::cout << "Muted" << std::endl;
	}
}

