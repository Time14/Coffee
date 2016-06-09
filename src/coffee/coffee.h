#ifndef __COFFEE__H__
#define __COFFEE__H__

#include <string>

namespace coffee {

	struct VideoInfo {
		uint16_t width;
		uint16_t height;
		bool fullScreen;
	};

	void init(std::string name) {

		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			printf("Failed to init SDL.");
			exit(-1);
		}


	}
}

#endif
