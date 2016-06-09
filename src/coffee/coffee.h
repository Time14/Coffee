#ifndef __COFFEE__H__
#define __COFFEE__H__

#include "include.h"
#include <string>

namespace coffee {

	Display display;

	void init(std::string name) {

		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			printf("Failed to init SDL.");
			exit(-1);
		}
		display();
	}
}

#endif
