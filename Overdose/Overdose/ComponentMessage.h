#pragma once
namespace overdose {
	enum ComponentMessage {
		/* naamgevingsconventie: ComponentNaam_MESSAGE */
		PlayerInputComponent_ATTACK,
		CollissionComponent_COLLISION_TOP,
		CollissionComponent_COLLISION_BOTTOM,
		CollissionComponent_COLLISION_LEFT,
		CollissionComponent_COLLISION_RIGHT,
		ClickableComponent_CLICK,
		Player_ATTACKING,

	};
}