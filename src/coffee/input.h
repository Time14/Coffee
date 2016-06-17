#ifndef __INPUT__H__
#define __INPUT__H__

namespace coffee {
	enum InputState {
		KEY_RELEASED = -2,
		KEY_UP = 0,
		KEY_DOWN = 1,
		KEY_PRESSED = 2
	};

	enum class InputType {
		KEY_DOWN,
		KEY_UP,
		MOUSE_MOVE,
		MOUSE_CLICK,
		MOUSE_RELEASE,
		BUTTON_DOWN,
		BUTTON_UP,
		CONTROLLER_ADD,
		CONTROLLER_REMOVE
	};
}

#endif // !__INPUT__H__