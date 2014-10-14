#pragma once
namespace overdose {
	enum ComponentMessage {
		/* naamgevingsconventie: ComponentNaam_MESSAGE */
		PlayerInputComponent_ATTACK,
		CollissionComponent_COLLISION_TOP,
		CollissionComponent_COLLISION_BOTTOM,
		CollissionComponent_COLLISION_LEFT,
		CollissionComponent_COLLISION_RIGHT,
		CollissionComponent_REACTION_TOP,
		CollissionComponent_REACTION_BOTTOM,
		CollissionComponent_REACTION_LEFT,
		CollissionComponent_REACTION_RIGHT,
		ClickableComponent_CLICK,
		Player_ATTACKING,

	};
}