#include "display.h"

namespace coffee {

	Display::Display() {
		_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_OPENGL);
	}

	Display::~Display() {

	}

	int Display::update() {
		return 0;
	}

	void Display::setWidth(uint16_t width) {
		_width = width;
	}

	void Display::setHeight(uint16_t height) {
		_height = height;
	}

	void Display::setFullScreen(bool fullScreen) {
		_fullScreen = fullScreen;

		if (_fullScreen == DisplayMode::WINDOW) {
			SDL_SetWindowFullscreen(_window, 0);

		} else if (_fullScreen == DisplayMode::FULLSCREEN) {
			SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN);

		} else if (_fullScreen == DisplayMode::BORDERLESS) {
			SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
		}
	}

	void Display::setTitle(std::string title) {
		_title = title;
		SDL_SetWindowTitle(_window, _title.c_str());
	}

}