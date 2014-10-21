#pragma once
#include "stdafx.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>

namespace overdose {
	enum eMusic{
		Stop,
		MainMenuTheme,
		Street

	};

	enum eSound{
		High,
		Medium,
		Low,
		Scratch,
		Death,
		GameOverSound
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
		

		//The sound effects that will be used
		Mix_Chunk *gHigh = NULL;
		Mix_Chunk *gMedium = NULL;
		Mix_Chunk *gLow = NULL;
		Mix_Chunk *gDeath = NULL;
		Mix_Chunk *gGameOver = NULL;
	};

}