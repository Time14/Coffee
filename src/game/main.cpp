#include <iostream>
#include "coffee.h"

int main(int argc, char* argv[]) {

	coffee::Bean core;

	coffee::InputManager::addInput(coffee::InputData(-1, SDLK_ESCAPE, 0), "quit");

	core.brew();

	return 0;
}
 