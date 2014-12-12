#pragma once
namespace overdose {
	enum eGameEntity {
		Player, Policeman, DrugAddict, Junky, Drugdealer, FPSCounter, Environment, Drug_Speed, Drug_Marijuana, Drug_XTC, Grass, Flag,

		/*Advertisement */
		Advertisement_GameEntity,

		/*Main Menu*/
		ButtonPlay, ButtonHighScore,

		/*Win/GameOver Menu*/
		TextBox, ButtonPlayAgain, ButtonMainMenu, ButtonQuitGame, ButtonQuitGameGreen, ButtonPlayAgainGreen, ButtonMainMenuGreen,ButtonCredits, ButtonLoadGame,

		/* Particle */
		Particle,

		/* Text */
		Text,

		/* Tutorial */
		FocusPointer, Tutorial_Policeman, Tutorial_Drug_Speed, Tutorial_Drug_Marijuana, Tutorial_Drug_XTC
	};
	enum eFacing {
		Left, FrontView, Right
	};
}