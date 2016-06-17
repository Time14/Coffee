#include "include.h"

#include <string>

namespace coffee {

	enum DisplayMode {
		WINDOW, 
		FULLSCREEN, 
		BORDERLESS
	};

	class Display {
	public:
		Display();
		~Display();

		int update();

		void setWidth(uint16_t width);
		void setHeight(uint16_t height);
		void setFullScreen(bool fullScreen);
		void setTitle(std::string title);

		uint16_t getWidth() { return _width; }
		uint16_t getHeight() { return _height; }

		uint8_t getFullScreen() { return _fullScreen; }

		std::string getTitle() { return _title; }

	private:

		SDL_Window* _window = 0;
		SDL_GLContext _context = 0;

		uint16_t _width = 400;
		uint16_t _height = 500;

		uint8_t _fullScreen = DisplayMode::WINDOW;

		std::string _title = "Coffee";
	};
}