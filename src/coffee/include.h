//////////////////////////////////////////////////
// This file is here to make sure the import	//
// process is handled smothly. Since the		//
// OS-s have different include directories.		//
//////////////////////////////////////////////////

#ifndef __INCLUDE__H__
#define __INCLUDE__H__
	//All os-s
	#ifdef __linux__
    		//Linux specific
    		#include <SDL2/SDL.h>
    		#include <GL/glew.h>
#include <GL/gl.h>

	#else
			//Windows specific
    		#include "GLEW\glew.h"
			#include "SDL2\SDL.h"
    		#include <GL\gl.h>

	#endif
#endif
