#include "display.h"

namespace coffee {

	Display::Display(std::string name, int width, int height, uint32_t flags) {
		_window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags | SDL_WINDOW_OPENGL);
		_context = SDL_GL_CreateContext(_window);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


	}

	Display::~Display() {
		SDL_GL_DeleteContext(_context);
	}

	void Display::update() {
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		SDL_GL_SwapWindow(_window);

		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.window.event == SDL_WINDOWEVENT_CLOSE) {
				
				//coffee::stop();
			}
		}
	}
}
