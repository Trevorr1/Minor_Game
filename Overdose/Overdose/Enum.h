#pragma once
namespace overdose {
	enum eGameEntity {
		Player, Policeman, DrugAddict, Junky, Drugdealer, FPSCounter, Environment, Drug_Speed, Drug_Marijuana, Drug_XTC, Grass, Flag,

		/*Main Menu*/
		ButtonPlay, 

		/*Win/GameOver Menu*/
		ButtonPlayAgain, ButtonMainMenu, ButtonQuitGame, ButtonQuitGameGreen, ButtonPlayAgainGreen, ButtonMainMenuGreen, TextBox
	};
	enum eFacing {
		Left, FrontView, Right
	};
}