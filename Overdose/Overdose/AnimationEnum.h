#pragma once
namespace overdose {
	enum eAnimationState {
		Default, //used for static things like a button, who will only have one spritesheet
		WalkLeft, WalkRight, IdleLeft, IdleRight, //, Attack, Jump, Fall
		JumpLeft, JumpRight
	};
}
