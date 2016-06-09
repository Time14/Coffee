#include "display.h"

namespace coffee {

	Display::Display(std::string name, int width, int height, uint32_t flags) {
		_window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags | 0);
	}
}
