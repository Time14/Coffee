#ifndef __FILE__H__
#define __FILE__H__

#include <iostream>

class AFile {
public:
	//Nice comment bro!
	AFile() { std::cout << "FILE! :>" << std::endl; }
	~AFile() { std::cout << "FILE! :<" << std::endl; }
};

#endif
