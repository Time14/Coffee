#ifndef __DISPLAY__H__
#define __DISPLAY__H__

#include "include.h"

#include <string>

namespace coffee {
	class Display {
	public:
		Display(std::string name, int width, int height, uint32_t flags);
		~Display();

		void update();
		void draw();

	private:
		SDL_Window* _window;
		SDL_GLContext _context;

	};
}

#endif
