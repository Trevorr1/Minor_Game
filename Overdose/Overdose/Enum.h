#pragma once
namespace overdose {
	enum eGameEntity {
		// @#@#$@#$#@$ PUBLIC SERVICE ANNOUNCEMENT!!!@@#@#@##@
		// Je sloopt de bestaande levels als je de volgorde van nieuwe enums aanpast. Nieuwe entities? VOEG DEZE ACHTER AAN DE LIJST TOE!!!!!!
		Player, Policeman, DrugAddict, Junky, Drugdealer, FPSCounter, Environment, Drug_Speed, Drug_Marijuana, Drug_XTC, Grass, Flag, Ground,

		/*Advertisement */
		Advertisement_GameEntity,

		/*Main Menu*/
		ButtonPlay, ButtonHighScore, ButtonOptions,

		/*Win/GameOver Menu*/
		TextBox, ButtonPlayAgain, ButtonMainMenu, ButtonQuitGame, ButtonQuitGameGreen, ButtonPlayAgainGreen, ButtonMainMenuGreen,ButtonCredits, ButtonLoadGame,

		/* Particle */
		Particle,

		/* Options */
		ButtonGeneral, ButtonDrugs, ButtonControls, ButtonOptionsBack, OptionsMarijuana, OptionsSpeed, OptionsXTC, OptionsArrowRight, OptionsArrowLeft, OptionsSpacebar,

		/* Text */
		Text,

		/* Tutorial */
		Tutorial_Explanation, FocusPointer, Tutorial_Policeman, Tutorial_Drug_Speed, Tutorial_Drug_Marijuana, Tutorial_Drug_XTC,

		/* boss */
		Bullet, Urquhart,

		//TODO 
		/* Tutorial #2*/
		Tutorial_Level1, Tutorial_Level2, Tutorial_Level3, Tutorial_Arrow_Keys, Tutorial_Spacebar, Tutorial_Goal, Tutorial_HUD, Tutorial_Respawn, Tutorial_SpeedDrug, Tutorial_Cop


	};
	enum eFacing {
		Left, FrontView, Right
	};
}