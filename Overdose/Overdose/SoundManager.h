#pragma once
#include "stdafx.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>

namespace overdose {
	enum eMusic{
		Stop,
		MainMenuTheme,
		Street,
		People

	};

	enum eSound{
		Click,
		Death,
		GameOverSound,
		PartyHorn
	};

	class SoundManager
	{
	public:
		~SoundManager();
		static SoundManager* getInstance();

		void StopMusic();
		void PlayMusic(eMusic music);
		void PlaySound(eSound sound);

	private:
		SoundManager();
		static SoundManager* _instance;

		//Loads media
		bool init();
		bool loadMedia();

		//The music that will be played
		Mix_Music *gMusicMainMenu = NULL;
		Mix_Music *gMusicStreet = NULL;
		Mix_Music *gPeople = NULL;
		

		//The sound effects that will be used
		Mix_Chunk *gClick = NULL;
		Mix_Chunk *gDeath = NULL;
		Mix_Chunk *gGameOver = NULL;
		Mix_Chunk *gPartyHorn = NULL;
		

		 
	};

}