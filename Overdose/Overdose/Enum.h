#pragma once
namespace overdose {
	enum eGameEntity {
		Player, Policeman, DrugAddict, Junky, Drugdealer, FPSCounter, Environment, Drug_Speed, Drug_Marijuana, Drug_XTC, Grass, Flag,

		/*Advertisement */
		Advertisement_GameEntity,

		/*Main Menu*/
		ButtonPlay, 

		/*Win/GameOver Menu*/
		TextBox, ButtonPlayAgain, ButtonMainMenu, ButtonQuitGame, ButtonQuitGameGreen, ButtonPlayAgainGreen, ButtonMainMenuGreen,

		/* Particle */
		Particle
	};
	enum eFacing {
		Left, FrontView, Right
	};
}