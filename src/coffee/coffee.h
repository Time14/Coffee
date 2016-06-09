#ifndef __COFFEE__H__
#define __COFFEE__H__

#include "include.h"
#include "display.h"

#include <string>


namespace coffee {

	Display* display;
	bool running = true;

	void init(std::string name) {

		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			printf("Failed to init SDL.");
			exit(-1);
		}

		display = new Display(name, 400, 300, 0);
	}

	void run() {
		while (running) {
			display->update();
		}
	}

	void stop() {
		running = false;
	}

	void quit() {
		delete display;
	}
}

#endif
