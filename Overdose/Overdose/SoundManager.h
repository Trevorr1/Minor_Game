#pragma once
#include "stdafx.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>

namespace overdose {
	enum Music{
		Stop,
		MainMenu
	};

	enum Sound{
		High,
		Medium,
		Low,
		Scratch
	};

	class SoundManager
	{
	public:
		~SoundManager();
		static SoundManager* getInstance();

		void StopMusic();
		void PlayMusic(Music music);
		void PlaySound(Sound sound);

	private:
		SoundManager();
		static SoundManager* _instance;

		//Loads media
		bool init();
		bool loadMedia();

		//The music that will be played
		Mix_Music *gMusicMainMenu = NULL;

		//The sound effects that will be used
		Mix_Chunk *gHigh = NULL;
		Mix_Chunk *gMedium = NULL;
		Mix_Chunk *gLow = NULL;
	};

}