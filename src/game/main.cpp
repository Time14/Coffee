#include <iostream>
#include "coffee.h"

int main(int argc, char* argv[]) {

	printf("Hello world!\n");

	coffee::init("Hello World");

	coffee::run();

	coffee::quit();

#ifndef __linux__
	system("PAUSE");
#endif
	return 0;
}
