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
		People,
		BossFight

	};

	enum eSound{
		Click,
		Death,
		GameOverSound,
		PartyHorn,
		Ouch,
		PickUp
	};

	class SoundManager
	{
	public:
		~SoundManager();
		static SoundManager &getInstance();

		void StopMusic();
		void PlayMusic(eMusic music);
		void PlaySound(eSound sound);
		void PlaySound1(eSound sound); // fallback in case PlaySound is overwritten by a define.
		void ToggleMute();
		void ToggleMute(bool mute);
		
	private:
		SoundManager();
		static SoundManager* _instance;

		//mute boolean
		bool m_mute = false;

		//Loads media
		bool init();
		bool loadMedia();

		//The music that will be played
		Mix_Music *gMusicMainMenu = NULL;
		Mix_Music *gMusicStreet = NULL;
		Mix_Music *gPeople = NULL;
		Mix_Music *gBossFight = NULL;


		//The sound effects that will be used
		Mix_Chunk *gClick = NULL;
		Mix_Chunk *gDeath = NULL;
		Mix_Chunk *gGameOver = NULL;
		Mix_Chunk *gPartyHorn = NULL;
		Mix_Chunk *gOuch = NULL;
		Mix_Chunk *gPickUp = NULL;

		void SetVolume();

	};

}