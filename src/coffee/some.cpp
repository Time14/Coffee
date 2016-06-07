#include "some.h"


Some::Some() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	std::cout << "Start" << std::endl;
}

Some::~Some() {
	std::cout << "End" << std::endl;
}
